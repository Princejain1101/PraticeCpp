//
//  mergeIntervals.hpp
//  leetcode
//
//  Created by Prince Jain on 6/18/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef mergeIntervals_hpp
#define mergeIntervals_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
bool comparator(const vector<int> &a, const vector<int> &b){
    if(a[0] < b[0])
        return true;
    return false;
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result(intervals);
        sort(result.begin(),result.end(),comparator);
        int j=1;
        int i=0;
        while(j < result.size()){
            if(result[i][1] >= result[j][0]){
                result[i][1] = max(result[i][1],result[j][1]);
                result.erase(result.begin()+j);
            }else{
                i++;
                j++;
            }
        }
        return result;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> intervals({{1,3},{2,6},{8,10},{15,18}});
    vector<vector<int>> result = s.merge(intervals);
    for(auto &res:result){
        for(auto &v:res){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}
void test2(){
    Solution s;
    vector<vector<int>> intervals({{1,4},{4,5}});
    vector<vector<int>> result = s.merge(intervals);
    for(auto &res:result){
        for(auto &v:res){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}
void test3(){
    Solution s;
    vector<vector<int>> intervals({{1,4},{2,3}});
    vector<vector<int>> result = s.merge(intervals);
    for(auto &res:result){
        for(auto &v:res){
            cout<<v<<" ";
        }
        cout<<endl;
    }
}

#endif /* mergeIntervals_hpp */
