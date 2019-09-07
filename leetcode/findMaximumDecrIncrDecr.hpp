//
//  findMaximumDecrIncrDecr.hpp
//  leetcode
//
//  Created by Prince Jain on 6/28/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findMaximumDecrIncrDecr_hpp
#define findMaximumDecrIncrDecr_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    int _maxDID(vector<int>& nums, int start, int end){
        if(start==end) return nums[start];
        if(end < start) return -1;
        if(end - start == 1){
            if(nums[end]>nums[start]) return nums[end];
            else return nums[start];
        }
        int mid = (start+end)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return nums[mid];
        if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1])
            return _maxDID(nums, mid+1, end);
        if(nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]){
            if(nums[mid] < nums[end])
                return _maxDID(nums, mid+1, end);
            return _maxDID(nums, start, mid-1);
        }
        return _maxDID(nums, mid+1, end);
    }
    int _mimDID(vector<int>& nums, int start, int end){
        if(start==end) return nums[start];
        if(start>end) return -1;
        if(end-start==1){
            if(nums[start]<nums[end]) return nums[start];
            else return nums[end];
        }
        int mid = (start+end)/2;
        if(nums[mid] < nums[start] && nums[mid] < nums[end]) return nums[mid];
        if(nums[mid] > nums[start] && nums[mid] < nums[end])
            return _mimDID(nums, start, mid-1);
        if(nums[mid] < nums[start] && nums[mid] > nums[end]){
            if(nums[mid] < nums[end]){
                return _mimDID(nums, mid+1, end);
            }else{
                return _mimDID(nums, start, mid-1);
            }
        }
        return _mimDID(nums, start, mid-1);
    }
public:
    int maximumDecrIncrDecr(vector<int>& nums) {
        int n = (int)nums.size();
        return _maxDID(nums, 0, n-1);
    }
    int minimumDecrIncrDecr(vector<int>& nums){
        int n = (int)nums.size();
        return _mimDID(nums, 0, n-1);
    }
};
void test1(){
    Solution s;
    vector<int> nums({10, 8, 6, 5, 4, 3,130000, 20, 19, 18, 13});
    cout<<s.maximumDecrIncrDecr(nums)<<endl;
    cout<<s.minimumDecrIncrDecr(nums)<<endl;
}
#endif /* findMaximumDecrIncrDecr_hpp */
