//
//  minimumSizeSubarraySum.hpp
//  leetcode
//
//  Created by Prince Jain on 6/26/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef minimumSizeSubarraySum_hpp
#define minimumSizeSubarraySum_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = (int)nums.size();
        if(size==0) return 0;
        int minlen = size+1;
        int start=0;
        int sum=0;
        for(int i=0; i<size; i++){
            if(nums[i] >= s) return 1;
            sum = sum + nums[i];
            while(sum >= s){
                minlen = min(minlen, i-start+1);
                sum = sum - nums[start++];
                if(start > i) break;
            }
            if(sum<0){
                start = i+1;
                sum=0;
            }
        }
        return minlen;
    }
};
void test1(){
    Solution s;
    vector<int> nums({- 8, 1, 4, -1, 2, -6});
    cout<< s.minSubArrayLen(6, nums) <<endl;

}
#endif /* minimumSizeSubarraySum_hpp */
