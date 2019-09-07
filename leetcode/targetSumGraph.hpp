//
//  targetSumGraph.hpp
//  leetcode
//
//  Created by Prince Jain on 6/29/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef targetSumGraph_hpp
#define targetSumGraph_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    int _targetSumUtil(vector<int>& nums, vector<map<int,int>>& targetsum, int idx, int S, int total){
//        cout<<"total: "<<total<<endl;
        int n = (int)nums.size();
        if(idx == n) {
//            cout<<"reached end: "<<n<<", total: "<<total<<endl;
            if(S==total) return 1;
            else return 0;
        }
//        cout<<"nums[idx]: "<<nums[idx]<<endl;
        if(targetsum[idx].find(total) != targetsum[idx].end()){
            return targetsum[idx][total];
        }
        int counts=0;
        counts += _targetSumUtil(nums, targetsum, idx+1, S, total-nums[idx]);
        counts += _targetSumUtil(nums, targetsum, idx+1, S, total+nums[idx]);
        targetsum[idx][total]=counts;
        return counts;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = (int)nums.size();
        vector<map<int,int>> targetsum(n);
        return _targetSumUtil(nums, targetsum, 0, S, 0);
    }
//    int findTargetSumWays2(vector<int>& nums, int S){
//        int n = (int)nums.size();
//        vector<map<int,int>> targetsum(n);
//        
//    }
};
void test1(){
    Solution s;
    vector<int> nums({1,1,1,1,1});
    int S=3;
    cout<<s.findTargetSumWays(nums, S)<<endl;
}
void test2(){
    Solution s;
    vector<int> nums({9,7,0,3,9,8,6,5,7,6});
    int S=2;
    cout<<s.findTargetSumWays(nums, S)<<endl;
}
#endif /* targetSumGraph_hpp */
