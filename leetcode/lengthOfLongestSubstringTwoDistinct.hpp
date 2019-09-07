//
//  lengthOfLongestSubstringTwoDistinct.hpp
//  leetcode
//
//  Created by Prince Jain on 6/9/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef lengthOfLongestSubstringTwoDistinct_hpp
#define lengthOfLongestSubstringTwoDistinct_hpp

#include <stdio.h>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size()==0){
            return 0;
        }
        int ret=0;
        int start=0;
        int continuous = 0;
        set<char> twochars;
        //twochars.insert(s[0]);
//        std::cout<<"test"<<std::endl;
        for(int i=0; i<s.size(); i++){
            std::cout<<s[i]<<std::endl;
            if(twochars.find(s[i]) == twochars.end() && twochars.size()<2){
                twochars.insert(s[i]);
                twochars.insert(s[continuous]);
                continuous = i;
            }
            if(twochars.find(s[i]) == twochars.end() && twochars.size()==2){
                start = continuous;
                continuous = i;
                twochars.clear();
                twochars.insert(s[start]);
                twochars.insert(s[continuous]);
            }
            if(twochars.find(s[i]) != twochars.end() && twochars.size()==2 && s[continuous] != s[i]){
                continuous = i;
            }
            if(twochars.size()<=2){ //twochars.find(s[i]) != twochars.end() &&
                std::cout<<"ret: "<<ret<<", start: "<<start<<", i: "<<i<<std::endl;
                ret = (ret > i-start+1) ? ret : i-start+1;
            }
        }
        return ret;
    }
};

#endif /* lengthOfLongestSubstringTwoDistinct_hpp */
