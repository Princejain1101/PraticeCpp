//
//  pairSumClosestToK.hpp
//  leetcode
//
//  Created by Prince Jain on 7/1/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef pairSumClosestToK_hpp
#define pairSumClosestToK_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    void pairClosest(vector<int>& nums, int sum, int &a, int &b) {
        int l = 0;
        int r = (int)nums.size()-1;
        int minDiff = INT_MAX;
        while(l<r){
            int sum2 = nums[l]+nums[r];
            if(abs(sum2-sum)<minDiff){
                minDiff = abs(sum2-sum);
                a=nums[l];b=nums[r];
            }
            if(sum2<sum) l++;
            else r--;
        }
    }
};
void test1(){
    Solution s;
    vector<int> nums({10, 22, 28, 29, 30, 40});
    int a, b;
    s.pairClosest(nums, 54, a, b);
    cout<<a<<" "<<b<<endl;
    
    vector<int> nums2({1, 3, 4, 7, 10});
    s.pairClosest(nums2, 15, a, b);
    cout<<a<<" "<<b<<endl;

}

#endif /* pairSumClosestToK_hpp */
