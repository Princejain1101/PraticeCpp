//
//  main.cpp
//  leetcode
//
//  Created by Prince Jain on 6/2/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#include <iostream>
#include "numUniqueEmails.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    vector<string> emails({"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"});
    Solution s;
    cout<< s.numUniqueEmails(emails)<<endl;
    return 0;
}
