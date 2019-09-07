//
//  longestTrue.hpp
//  leetcode
//
//  Created by Prince Jain on 6/27/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef longestTrue_hpp
#define longestTrue_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int longestTrue(vector<bool>& vec) {
        if(vec.size()==0) return 0;
        int maxlen=0;
        int count=0;
        for(int i=0; i<vec.size(); i++){
            if(vec[i]==false){
                if(count>0) cout<<count<<endl;
                count=0;
                continue;
            }
            count++;
            maxlen = max(maxlen, count);
        }
        if(count>0) cout<<count<<endl;
        return maxlen;
    }
    int longestTrueCircular(vector<bool>& vec) {
        if(vec.size()==0) return 0;
        int n = (int)vec.size();
        int maxlen=0;
        int count=0;
        for(int i=0; i<n || (i>=n && vec[i%n]==true); i++){
            int j = i%n;
            if(vec[j]==false){
                count=0;
                continue;
            }
            count++;
            maxlen = max(maxlen, count);
        }
        return maxlen;
    }
    int maxDiff(string s){
        int diff=0;
        int maxdiff = -1;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') diff++;
            else diff--;
            if(diff<0) diff=0;
            maxdiff = max(maxdiff, diff);
        }
        if(s == string(s.size(),'1')) return -1;
        return maxdiff;
    }
};
void test1(){
    Solution s;
    vector<bool> vec({1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1});
    cout<<s.longestTrue(vec)<<endl;
//    cout<<s.longestTrueCircular(vec)<<endl;
//    cout<<s.maxDiff("11000010001")<<endl;
//    cout<<s.maxDiff("1111")<<endl;

}

#endif /* longestTrue_hpp */
