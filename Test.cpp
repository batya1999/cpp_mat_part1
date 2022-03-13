/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Batya Ashkenazi>
 * 
 * Date: 2021-02
 */
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
    
	 CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@\n"));

   

     CHECK(nospaces(mat(3, 3, '$', '-')) == nospaces("$$$\n"
													 "$-$\n"
													 "$$$"));

     CHECK(nospaces(mat(3, 3, '@', '-')) == nospaces(" @@@ " 
													 " @-@ "
													 " @@@ ")); 
                                                     
     CHECK(nospaces(mat(1, 1, '$', '-')) == nospaces("$")); 

     CHECK(nospaces(mat(1, 7, '$', '-')) == nospaces("$\n"
													 "$\n"
													 "$\n"
													 "$\n"
													 "$\n"
													 "$\n"
													 "$"));  

     CHECK(nospaces(mat(5, 1, '@', '-')) == nospaces("@@@@@"));                                                 
                                                     
                                                     }

/******************************************************/

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));

    CHECK_THROWS(mat(9, 2, '@', '%'));

    CHECK_THROWS(mat(4, 6, '!', '@'));

    CHECK_THROWS(mat(0, 5, '#', '^'));

    CHECK_THROWS(mat(0, 22, '@', '*'));

    CHECK_THROWS(mat(2, 5, '$', '&'));
}


TEST_CASE("not equals") {
    CHECK_NE(mat(3,3,'%','!'),"\n%%%\n%(%\n%%%");
    CHECK_NE(mat(3,7,'@','$'),mat(3,7,'%','&'));
    CHECK_NE(mat(3,5,'@','$'),mat(3,5,'%','&'));
    CHECK_NE(mat(1,3,'#','$'),mat(3,1,'#','$'));
    CHECK_NE(mat(11,13,'(','$'),mat(11,13,'$','('));
    CHECK_NE(mat(9,7,'#','$'),mat(9,7,'%','&'));
    CHECK_NE(mat(1,1,'@','$'),mat(1,1,'$','@'));
  
}

TEST_CASE("equals") {
    CHECK_EQ(mat(3,7,'^','$'),mat(3,7,'^','$'));
    CHECK_EQ(mat(1,7,'@','$'),mat(1,7,'@','!'));
    CHECK_EQ(mat(5,1,'#','%'),mat(5,1,'#','@'));
    CHECK_EQ(mat(1,7,'@','$'),mat(1,7,'@','!'));
    CHECK_EQ(mat(3,3,'$','@'),("$$$\n"
							   "$@$\n"
							   "$$$"));

}



    