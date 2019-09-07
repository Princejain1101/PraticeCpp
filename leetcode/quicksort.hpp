//
//  quicksort.hpp
//  leetcode
//
//  Created by Prince Jain on 7/1/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef quicksort_hpp
#define quicksort_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    int _partition(vector<int>& nums, int low, int high){
        if(high<low) return -1;
        if(low==high) return low;
        int start = low-1;
        int pivot = nums[high];
        for(int i=low; i<high; i++){
            if(nums[i]<=pivot){
                start++;
                swap(nums[start],nums[i]);
            }
        }
        start++;
        swap(nums[start],nums[high]);
        
        return start;
    }
    void _quickSortUtil(vector<int>& nums, int low, int high){
        if(low<high){
            int pivot = _partition(nums, low, high);
            _quickSortUtil(nums, low, pivot-1);
            _quickSortUtil(nums, pivot+1, high);
        }
    }
    int _kthSmallestUtil(vector<int>& nums, int low, int high, int k){
        if(low==high) return low;
        if(low<high){
            int pivot = _partition(nums, low, high);
            if(pivot==k) return nums[pivot];
            if(pivot>k){
                return _kthSmallestUtil(nums, low, pivot-1, k);
            }else{
                return _kthSmallestUtil(nums, pivot+1, high, k);
            }
        }
        return -1;
    }
public:
    void quickSort(vector<int>& nums) {
        _quickSortUtil(nums, 0, (int)nums.size()-1);
    }
    
    int kthSmallest(vector<int>& nums, int k){
        return _kthSmallestUtil(nums, 0, (int)nums.size()-1, k-1);
    }
};
void test1(){
    Solution s;
    vector<int> nums({10, 7, 8, 9, 1, 5});
    s.quickSort(nums);
    for(auto &i:nums) cout<<i<<",";
    cout<<endl;
    cout<<s.kthSmallest(nums, 4)<<endl;
}
#endif /* quicksort_hpp */
