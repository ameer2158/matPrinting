#include "doctest.h"
#include "mat.hpp"

#include <string>
#include <algorithm>

using namespace ariel;
using namespace std;

string nospaces(string input) {
	erase(input, ' ');
	erase(input, '\t');
	erase(input, '\n');
	erase(input, '\r');
	return input;
}

TEST_CASE("Good Input")
{
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK(nospaces(mat(9, 7, '@', '+')) == nospaces("@@@@@@@@@\n@+++++++@\n@+@@@@@+@\n@+@+++@+@\n@+@@@@@+@\n@+++++++@\n@@@@@@@@@"));
    CHECK(nospaces(mat(13, 5, '$', '-')) == nospaces("$$$$$$$$$$$$$\n$-----------$\n$-$$$$$$$$$-$\n$-----------$\n$$$$$$$$$$$$$"));
    CHECK(nospaces(mat(13, 5, '#', '^')) == nospaces("#############\n#^^^^^^^^^^^#\n#^#########^#\n#^^^^^^^^^^^#\n#############"));
    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n$+$\n$+$\n$+$\n$$$"));
    CHECK(nospaces(mat(3, 5, '#', ')')) == nospaces("###\n#)#\n#)#\n#)#\n###"));
    CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));
    CHECK(nospaces(mat(1, 1, '#', '+')) == nospaces("#"));	
    CHECK(nospaces(mat(1, 1, '$', ')')) == nospaces("$"));	
}

TEST_CASE("Bad Input")
{
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(10, 5, '$', '-'));
    CHECK_THROWS(mat(10, 5, '@', '+'));
    CHECK_THROWS(mat(10, 5, '#', '^'));
    CHECK_THROWS(mat(9 , 4, '$', '%'));
    CHECK_THROWS(mat(0, 2, '$', '%'));
    CHECK_THROWS(mat(16, 0, '$', '%'));
    CHECK_THROWS(mat(9, -2, '$', '%'));
    CHECK_THROWS(mat(-3, -5, '$', '%'));
    CHECK_THROWS(mat(-3, 5, '$', '%'));
    CHECK_THROWS(mat(0, 4, '$', '%'));
}