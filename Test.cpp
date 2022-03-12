/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Josef Sokolov 
 * 
 * ID: 337959928
 * 
 * DATE: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
#include "doctest.h"
#include <string>
#include <algorithm>
#include <stdexcept>
using namespace std;
using namespace ariel;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    erase(input, ' ');
    erase(input, '\t');
    erase(input, '\n');
    erase(input, '\r');
    return input;
}
TEST_CASE("Good input")
{
    CHECK(nospaces(mat(7, 3, '@', '-')) == nospaces("@@@@@@@\n@-----@\n@@@@@@@"));
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK(nospaces(mat(1, 3, '@', '-')) == nospaces("@\n@\n@"));
    CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@@@")); 
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n@-----------@\n@-@@@@@@@@@-@\n@-----------@\n@@@@@@@@@@@@@"));
    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n$+$\n$+$\n$+$\n$$$"));
    CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));
    CHECK(nospaces(mat(1, 1, '@', ')')) == nospaces("@"));
    CHECK(nospaces(mat(1, 1, ')', '@')) == nospaces(")"));
    CHECK(nospaces(mat(15, 11, '@', '-')) == nospaces("@@@@@@@@@@@@@@@\n@-------------@\n@-@@@@@@@@@@@-@\n@-@---------@-@\n@-@-@@@@@@@-@-@\n@-@-@-----@-@-@\n@-@-@@@@@@@-@-@\n@-@---------@-@\n@-@@@@@@@@@@@-@\n@-------------@\n@@@@@@@@@@@@@@@"));
    CHECK(nospaces(mat(7, 1, '@', '-')) == nospaces("@@@@@@@"));

}
TEST_CASE("Bad input")
{
    //zero
    CHECK_THROWS(mat(0, 0, '@', '-'));
    CHECK_THROWS(mat(0, 7, '@', '-'));
    CHECK_THROWS(mat(3, 0, '@', '-'));
    //minus
    CHECK_THROWS(mat(-3, 7, '@', '-'));
    CHECK_THROWS(mat(7, -1, '@', '-'));
    CHECK_THROWS(mat(-3, -7, '@', '-'));
    //even
    CHECK_THROWS(mat(2, 2, '@', '-'));
    CHECK_THROWS(mat(4, 7, '@', '-'));
    CHECK_THROWS(mat(7, 4, '@', '-'));
    //same
    CHECK_THROWS(mat(2, 3, '@', '@'));
    CHECK_THROWS(mat(2, 3, '#', '#'));
    CHECK_THROWS(mat(2, 3, '(', '('));
    //wrong symbol
    CHECK_THROWS(mat(9, 7, ' ', ' '));
    CHECK_THROWS(mat(9, 7, '@', ' '));
    CHECK_THROWS(mat(9, 7, '@', '\n'));
    CHECK_THROWS(mat(9, 7, '@', '\t'));
    CHECK_THROWS(mat(9, 7, '@', '\r'));
}
