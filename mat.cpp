#include "mat.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
namespace ariel
{
    char** transpose(char** transp, char** matrix, int row, int col){
        for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            transp[j][i] = matrix[i][j];
        return transp;
    } 
    char** init(char** matrix, int row, int col, char symbol1, char symbol2){
        for (int i = 0; i<row; i++){
            for (int j = 0; j<col; j++){
                if (i <= row/2 && matrix[i][j] != symbol1)
                {
                    if (i%2 == 0 && j>=i && j<=col-(i+1))
                        matrix[i][j] = symbol1;
                    else if (j==0)
                        matrix[i][j] = symbol1;
                    else if (j==col-1)
                        matrix[i][j] = symbol1;
                    else
                        matrix[i][j] = symbol2;
                }
                else if (matrix[i][j] != symbol1)
                {
                    if (i%2 == 0 && j>=row-(i+1) && j<=col-(row-i))
                        matrix[i][j] = symbol1;
                    else if (j==0)
                        matrix[i][j] = symbol1;
                    else if (j==col-1)
                        matrix[i][j] = symbol1;
                    else
                        matrix[i][j] = symbol2;
                }
            }
        }
        return matrix;
    }

    string mat(int col, int row, char symbol1, char symbol2)
    {
        string ans = "";

        if (row % 2 == 0 || col % 2 == 0)
        {
            throw runtime_error("Mat size is always odd");
        }
        else if (row == 0 || col == 0)
        {
            throw runtime_error("Mat size is always non-zero");
        }
        else if (row < 0 || col < 0)
        {
            throw runtime_error("Mat size is always positive");
        }
        else if (symbol1 < 33  || symbol2 < 33)
        {
            throw runtime_error("wrong symbol values");
        }
        else if (symbol1 == symbol2)
        {
            throw runtime_error("Entered wrong values: symbol1 and symbol2 need be a different symbols");
        }
        else
        {
            //CREATE  MATRIX
            char** matrix = new char*[row];
            for (int i = 0; i < row; ++i)
                matrix[i] = new char[col];
            //CALL INIT FUNC
            matrix = init(matrix, row, col, symbol1, symbol2);

            //CREATE TRANSP MATRIX
            char** transp = new char*[col];
            for (int i = 0; i < col; ++i)
                transp[i] = new char[row];
            //CALL TRANSPOSE FUNC    
            transp = transpose(transp, matrix, row, col);
            
            //CALL INIT FUNC
            transp = init(transp, col, row, symbol1, symbol2);

            //CALL TRANSPOSE FUNC    
            matrix = transpose(matrix, transp, col, row);

            //CONVERSE MARIX TO STRING
            for (int i = 0; i<row; i++){
                for (int j = 0; j<col; j++)
                    ans += matrix[i][j];
                ans +="\n";
            }

            //DELETE
            for (int i = 0; i < row; ++i)
                delete [] matrix[i];
            delete [] matrix;
            
            for (int i = 0; i < col; ++i)
                delete [] transp[i];
            delete [] transp;
        }
        return ans;
    }
}
