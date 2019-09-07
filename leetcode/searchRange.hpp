//
//  searchRange.hpp
//  leetcode
//
//  Created by Prince Jain on 6/18/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef searchRange_hpp
#define searchRange_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    vector<int> _searchRangeUtil(vector<int>& nums, int start, int end, int target){
        if(end<start){
            return vector<int>({-1,-1});
        }
        //last element
        if(end==start && nums[start]!=target){
            return vector<int>({-1,-1});
        }
        // all in the target
        if((end==start && nums[start]==target) || (nums[start]==target && nums[end]==target)){
            return vector<int>({start,end});
        }
        // none in target
        if(nums[end]<target || nums[start]>target){
            return vector<int>({-1,-1});
        }
        int low=(int)nums.size(); int high=-1;
//        if(nums[start]==target)
//            low = start;
//        if(nums[end]==target)
//            high = start;
        int mid = (start+end)/2;
        vector<int> leftsearch = _searchRangeUtil(nums, start, mid, target);
        vector<int> rightsearch = _searchRangeUtil(nums, mid+1, end, target);
        int leftlow = leftsearch[0];
        int lefthigh = leftsearch[1];
        int rightlow = rightsearch[0];
        int righthigh = rightsearch[1];
        if(leftlow != -1 && leftlow < low){
            low = leftlow;
        }
        if(lefthigh != -1 && lefthigh < low){
            low = lefthigh;
        }
        if(rightlow != -1 && rightlow < low){
            low = rightlow;
        }
        if(righthigh != -1 && righthigh < low){
            low = righthigh;
        }
        if(low == nums.size()){
            low = -1;
        }
        high = max(max(leftlow, lefthigh),max(rightlow,righthigh));
        return vector<int>({low, high});
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return _searchRangeUtil(nums, 0, (int)nums.size()-1, target);
    }
};
void test1(){
    Solution s;
    vector<int> nums({5,7,7,8,8,10});
    vector<int> res = s.searchRange(nums, 9);
    for(auto &i:res){
        cout<<i<<" ";
    }
    cout<<endl;
}

#endif /* searchRange_hpp */
