//
//  lengthOfLongestSubstring.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef lengthOfLongestSubstring_hpp
#define lengthOfLongestSubstring_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int start = -1;
        int end = -1;
        for(auto &c: s){
            //std::cout<<c<<std::endl;
            size_t pos = start + 1 + (s.substr(start+1, end-start)).find(c);
            if(pos != string::npos){
                start = (int)pos;
            }
            end++;
            //std::cout<<"start: "<<start<<", end: "<<end<<std::endl;
            max = ((end - start) > max) ? end - start :  max;
        }
        
        return max;
    }
    int lengthOfLongestSubstring2(string s){
        if(s.size()==0)
            return 0;
        int start=0;
        int maxLen=1;
        for(int i=1;i<s.size(); i++){
            string sub = s.substr(start,i-start);
            int pos = (int)sub.find(s[i]);
            if(pos != string::npos){
                start = start + pos + 1;
            }
            maxLen = max(maxLen, i-start+1);
        }
        return maxLen;
    }
};
void test1(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("pwwkew")<<endl;
    cout<<s.lengthOfLongestSubstring2("pwwkew")<<endl;
}
#endif /* lengthOfLongestSubstring_hpp */
