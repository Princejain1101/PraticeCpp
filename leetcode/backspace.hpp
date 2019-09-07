//
//  backspace.hpp
//  leetcode
//
//  Created by Prince Jain on 6/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef backspace_hpp
#define backspace_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;
class Solution {
    void _createStack(stack<char> &stackT, string S){
        for(auto &s:S){
            if(s == '#'){
                if(!stackT.empty())
                    stackT.pop();
            }else{
                stackT.push(s);
            }
        }
    }
public:
    bool backspaceCompare(string S, string T) {
        stack<char> Sstack;
        stack<char> Tstack;
        _createStack(Sstack, S);
        _createStack(Tstack, T);
        if(Sstack.size() != Tstack.size()){
            return false;
        }
        for(int i=0; i<Sstack.size(); i++){
            if(Sstack.top() != Tstack.top()){
                return false;
            }
        }
        return true;
    }
};
void test1(){
    Solution s;
    std::cout<<s.backspaceCompare("ab#c", "ad#c")<<std::endl;
}
void test2(){
    Solution s;
    std::cout<<s.backspaceCompare("ab##", "c#d#")<<std::endl;
}

void test3(){
    Solution s;
    std::cout<<s.backspaceCompare("a##c", "#a#c")<<std::endl;
}

void test4(){
    Solution s;
    std::cout<<s.backspaceCompare("a#c", "b")<<std::endl;
}

#endif /* backspace_hpp */
