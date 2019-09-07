//
//  searchRotated.hpp
//  leetcode
//
//  Created by Prince Jain on 6/27/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef searchRotated_hpp
#define searchRotated_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
int _binarySearch(vector<int>& nums, int start, int end, int target){
    if(end<start) return -1;
    if(end == start && target == nums[start]) return start;
    if(end == start) return -1;
    int mid = (start+end)/2;
    if(nums[mid]==target) return mid;
    if(target < nums[mid]) return _binarySearch(nums, start, mid-1, target);
    else return _binarySearch(nums, mid+1, end, target);
}
class Solution {
    int searchRotated(vector<int>& nums, int target, int start, int end){
        if(start==end){
            if(target==nums[start]) return start;
            else return -1;
        }
        if(start>end) return -1;
        int mid = (start+end)/2;
        if(target==nums[mid]) return mid;
        if(nums[mid] < nums[start] && nums[mid] < nums[end]){
            if( target < nums[mid] && target <= nums[end])
                return _binarySearch(nums, mid+1, end, target);
            else
                return searchRotated(nums, target, start, mid-1);
        }
        if(nums[mid] > nums[start] && nums[mid] > nums[end]){
            if(target >= nums[start] && target < nums[mid])
                return _binarySearch(nums, start, mid-1, target);
            else
                return searchRotated(nums, target, mid+1, end);
        }
        if(target < nums[mid]) return _binarySearch(nums, start, mid-1, target);
        else return _binarySearch(nums, mid+1, end, target);
    }
public:
    int search(vector<int>& nums, int target) {
        return searchRotated(nums, target, 0, (int)nums.size()-1);
    }
};
void test1(){
    Solution s;
    vector<int> nums({4,5,6,7,0,1,2});
    cout<<s.search(nums, 3)<<endl;
}
#endif /* searchRotated_hpp */
