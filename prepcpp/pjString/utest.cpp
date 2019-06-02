// utest.cpp by Bill Weinman <http://bw.org/>
// version of 2018-10-12

#include <cstdio>
#include "BWUTest.h"
#include "PJString.hpp"

bool summary_flag = false;

int main()
{
    
    // Versions n things
    printf("BWUTest version: %s\n", BWUTest::version());
    
    BWUTest u("BWLib");
    u.summary(summary_flag);
    
    // BWString
    printf("\nTesting PJString -----\n");
    u.init("PJString");

    // test constructors
    const char * _ctest = "   \tfoo   \r\n";
    PJString pjtest = _ctest;
    u.test("cstring ctor pj", pjtest.length() == 12);
    
    PJString otherpj = std::move(pjtest);
    u.test("move ctor pj", otherpj.length() == 12 && pjtest.length() == 0);
    

    // assignment operators
    pjtest = std::move(otherpj);
    u.test("move assignment pj", otherpj.length() == 0 && pjtest.length() == 12);
    otherpj = pjtest;
    u.test("copy assignment pj", otherpj.length() == 12 && pjtest.length() == 12);

    // concat operators
    PJString xpj = "foo";
    PJString ypj = "bar";
    xpj += ypj;
    u.test("concat += pj ", xpj.length() == 6 && memcmp(xpj.c_str(), "foobar", 7) == 0);
    
    PJString zpj;
    zpj = xpj + "baz";
    u.test("concat + pj", zpj.length() == 9 && memcmp(zpj.c_str(), "foobarbaz", 10) == 0);
    zpj = "baz" + xpj;
    u.test("concat + pj", zpj.length() == 9 && memcmp(zpj.c_str(), "bazfoobar", 10) == 0);

    
    // comparison operators
    xpj = ypj = "foo";
    u.test("foo == foo -pj",   (xpj == ypj));
    u.test("foo  > foo -pj",  !(xpj  > ypj));
    u.test("foo >= foo -pj",   (xpj >= ypj));
    u.test("foo  < foo -pj",  !(xpj  < ypj));
    u.test("foo <= foo -pj",   (xpj <= ypj));
    
    xpj = "bar";
    u.test("bar == foo -pj",  !(xpj == ypj));
    u.test("bar  > foo -pj",  !(xpj  > ypj));
    u.test("bar >= foo -pj",  !(xpj >= ypj));
    u.test("bar  < foo -pj",   (xpj  < ypj));
    u.test("bar <= foo -pj",   (xpj <= ypj));
    
    u.test("foo == bar -pj",  !(ypj == xpj));
    u.test("foo  > bar -pj",   (ypj  > xpj));
    u.test("foo >= bar -pj",   (ypj >= xpj));
    u.test("foo  < bar -pj",  !(ypj  < xpj));
    u.test("foo <= bar -pj",  !(ypj <= xpj));
    
    
    // subscript
    u.test("subscript xpj[0]", xpj[0] == 'b');
    u.test("subscript xpj[1]", xpj[1] == 'a');
    u.test("subscript xpj[2]", xpj[2] == 'r');
    u.test("subscript terminator xpj[3]", xpj[3] == 0);
    
    pjtest.trim();
    u.test("trim - pj", pjtest.length() == 3);
    
    pjtest = "this is a string";
    u.test("length is 16 - pj", pjtest.length() == 16 && pjtest.size() == 16);
    u.test("substr - pj", pjtest.substr(10, 3) == PJString("str"));
    u.test("charfind - pj", pjtest.char_find('s') == 3);
    u.test("charfind (not found) - pj", pjtest.char_find('z') == -1);
    
    
    PJString string_upperpj = pjtest.upper();
    PJString string_lowerpj = string_upperpj.lower();
    u.test("upper and lower - pj", string_upperpj == PJString("THIS IS A STRING") && string_lowerpj == PJString("this is a string"));
    
    
    xpj = "this is a big string ###foobarbaz### this is a big string";
    xpj = xpj.replace("###foobarbaz###", "foo bar baz");
    u.test("replace - pj", xpj.length() == 53 && memcmp(xpj.c_str(), "this is a big string foo bar baz this is a big string", 54) == 0);
    
    
    xpj = "line one/line two/line three";
    auto & rpj = xpj.split('/');
    
    u.test("split_count is 3 - pj", xpj.split_count() == 3);
    u.test("split result 1 - pj", memcmp(rpj[0]->c_str(), "line one", 8) == 0);
    u.test("split result 2 - pj", memcmp(rpj[1]->c_str(), "line two", 8) == 0);
    u.test("split result 3 - pj", memcmp(rpj[2]->c_str(), "line three", 10) == 0);
    u.test("split test end - pj", !rpj[3]);
    
    
    // report results
    puts("");
    u.report();
    
    return 0;   // Done. Yay!
}
