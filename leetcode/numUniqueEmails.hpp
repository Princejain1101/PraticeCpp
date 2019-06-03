//
//  numUniqueEmails.hpp
//  leetcode
//
//  Created by Prince Jain on 6/2/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef numUniqueEmails_hpp
#define numUniqueEmails_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
    void _trim_name(string & s){
        // ignoring string after "+"
        auto pos = s.find("+");
        s = s.substr(0,pos);
        // erasing "." from local name
        while((pos = s.find(".")) != string::npos){
            s.erase(pos,1);
        }
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;
        for(auto i : emails){
            auto pos = i.find("@");
            string local_name = i.substr(0,pos);
            _trim_name(local_name);
            string domain_name = i.substr(pos);
            uniqueEmails.insert(local_name + "@" + domain_name);
        }
        return (int)uniqueEmails.size();
    }
};
#endif /* numUniqueEmails_hpp */
