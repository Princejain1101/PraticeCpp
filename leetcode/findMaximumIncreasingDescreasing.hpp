//
//  findMaximumIncreasingDescreasing.hpp
//  leetcode
//
//  Created by Prince Jain on 6/28/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findMaximumIncreasingDescreasing_hpp
#define findMaximumIncreasingDescreasing_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    int _findMaximum(vector<int>& nums, int start, int end){
        if(start>end) return -1;
        if(start==end) return nums[start];
        if(end - start == 1) {
            if(nums[start] > nums[end]) return nums[start];
            else return nums[end];
        }
        int mid = (start+end)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return nums[mid];
        }
        if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
            return _findMaximum(nums, mid+1, end);
        }
        return _findMaximum(nums, start, mid-1);
    }
public:
    int findMaximum(vector<int>& nums) {
        int n = (int)nums.size();
        return _findMaximum(nums, 0, n-1);
    }
};
void test1(){
    Solution s;
    vector<int> nums({8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1});
    cout<<s.findMaximum(nums)<<endl;
    vector<int> nums1({1, 3, 50, 10, 9, 7, 6});
    cout<<s.findMaximum(nums1)<<endl;
    vector<int> nums2({10, 20, 30, 40, 50});
    cout<<s.findMaximum(nums2)<<endl;
    vector<int> nums3({120, 100, 80, 20, 0});
    cout<<s.findMaximum(nums3)<<endl;

}
#endif /* findMaximumIncreasingDescreasing_hpp */
