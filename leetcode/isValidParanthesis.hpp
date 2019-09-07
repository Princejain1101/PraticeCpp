//
//  isValidParanthesis.hpp
//  leetcode
//
//  Created by Prince Jain on 6/11/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef isValidParanthesis_hpp
#define isValidParanthesis_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    bool _checkPair(char a, char b){
        if(a=='(' && b==')')
            return true;
        if(a=='[' && b==']')
            return true;
        if(a=='{' && b=='}')
            return true;
        return false;
    }
    bool _ifPush(char a){
        if( a== '(' || a=='[' || a=='{')
            return true;
        return false;
    }
public:
    bool isValid(string s) {
        bool ret = false;
        vector<char> braces;
        for(auto &c:s){
            if(_ifPush(c)){
                braces.push_back(c);
            }else{
                int size = (int)braces.size();
                if(size==0)
                    return false;
                if(_checkPair(braces[size-1],c)){
                    braces.erase(braces.end()-1);
                }else{
                    return false;
                }
            }
        }
        if(braces.size() ==0){
            return true;
        }
        return ret;
    }
};
void test1(){
    Solution s;
    std::cout<<(s.isValid("()[]{}") == true)<<std::endl;
}
void test2(){
    Solution s;
    std::cout<<(s.isValid("()") == true)<<std::endl;
}
void test3(){
    Solution s;
    std::cout<<(s.isValid("(]") == false)<<std::endl;
}
void test4(){
    Solution s;
    std::cout<<(s.isValid("([)]") == false)<<std::endl;
}
void test5(){
    Solution s;
    std::cout<<(s.isValid("{[]}") == true)<<std::endl;
}


#endif /* isValidParanthesis_hpp */
