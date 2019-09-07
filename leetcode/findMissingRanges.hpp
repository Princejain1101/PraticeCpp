//
//  findMissingRanges.hpp
//  leetcode
//
//  Created by Prince Jain on 6/9/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findMissingRanges_hpp
#define findMissingRanges_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
    string _getString(int lower, int upper){
        if(lower == upper){
            return to_string(lower);
        }else{
            return to_string(lower) + "->" + to_string(upper);
        }
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        if(nums.size() == 0){
            ret.push_back(_getString(lower, upper));
            return ret;
        }
        int low = lower;
        int up = upper;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            if(n > low ){
                ret.push_back(_getString(low, n-1));
            }
            if(n!= INT_MAX)
                low = n+1;
            else
                low = n;
        }
        if(up >= low && low != INT_MAX){
            ret.push_back(_getString(low, up));
        }
        return ret;
    }
};

#endif /* findMissingRanges_hpp */
