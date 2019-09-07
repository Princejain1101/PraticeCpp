//
//  findReplaceString.hpp
//  leetcode
//
//  Created by Prince Jain on 6/11/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findReplaceString_hpp
#define findReplaceString_hpp

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Solution {
    string _replaceAtPosition(string S, int pos, int len, string R){
        int firstLen = pos;
        int secondLen = (int)S.size() - (pos + len);
        return S.substr(0,firstLen) + R + S.substr(pos+len,secondLen);
    }
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int, int> shuffle;
        for(int i=0; i<indexes.size(); i++){
            shuffle.insert(pair<int, int>(indexes[i],i));
        }
        string ret = S;
        int next=0;
        for(auto it=shuffle.begin(); it != shuffle.end(); it++){
            int i = it->second;
            int index = indexes[i] + next;
//            std::cout<<"i: "<<i<<", indexes[i]: "<<indexes[i]<<", next: "<<next<<" index: "<<index<<std::endl;
            bool canReplace=true;
            int j=0;
            for(auto &s:sources[i]){
                if(ret[index+j] != s){
                    canReplace = false;
                    break;
                }
                j++;
            }
            if(canReplace){
                next += targets[i].size() - sources[i].size();
                ret = _replaceAtPosition(ret, index, (int)sources[i].size(), targets[i]);
//                std::cout<<"ret: "<<ret<<std::endl;
            }
        }
        return ret;
    }
};
void test1(){
    Solution s;
    string S = "abcd";
    vector<int> indexes = {0,2};
    vector<string> sources = {"a","cd"};
    vector<string> targets = {"eee","ffff"};
    std::cout<<s.findReplaceString(S, indexes, sources, targets)<<std::endl;
}
void test2(){
    Solution s;
    string S = "abcd";
    vector<int> indexes = {0,2};
    vector<string> sources = {"ab","ec"};
    vector<string> targets = {"eee","ffff"};
    std::cout<<s.findReplaceString(S, indexes, sources, targets)<<std::endl;
}
void test3(){
    Solution s;
    string S = "wreorttvosuidhrxvmvo";
    vector<int> indexes = {14,12,10,5,0,18};
    vector<string> sources = {"rxv","dh","ui","ttv","wreor","vo"};
    vector<string> targets = {"frs","c","ql","qpir","gwbeve","n"};
    std::cout<<s.findReplaceString(S, indexes, sources, targets)<<std::endl;
}
#endif /* findReplaceString_hpp */
