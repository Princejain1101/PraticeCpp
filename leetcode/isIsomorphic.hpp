//
//  isIsomorphic.hpp
//  leetcode
//
//  Created by Prince Jain on 6/19/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef isIsomorphic_hpp
#define isIsomorphic_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapchar;
        unordered_set<char> mapped;
        if(s.size() != t.size())
            return false;
        for(int i=0; i<s.size(); i++){
            char chars=s[i];
            char chart=t[i];
            if(mapchar.find(chars) == mapchar.end()){
                if(mapped.find(chart) != mapped.end())
                    return false;
                mapchar[chars]=chart;
                mapped.insert(chart);//=chars;
            }else{
                if(mapchar[chars]!=chart)
                    return false;
            }
        }
        return true;
    }
};
void test1(){
    Solution s;
    cout<<s.isIsomorphic("egg", "add")<<endl;
}
void test2(){
    Solution s;
    cout<<s.isIsomorphic("foo", "bar")<<endl;
}
void test3(){
    Solution s;
    cout<<s.isIsomorphic("paper", "title")<<endl;
}
void test4(){
    Solution s;
    cout<<s.isIsomorphic("ab", "aa")<<endl;
}
#endif /* isIsomorphic_hpp */
