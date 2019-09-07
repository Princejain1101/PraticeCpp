//
//  nextPermutation.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef nextPermutation_hpp
#define nextPermutation_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = (int)nums.size();
        int i = size-1;
        bool found = false;
        for(i = size-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                found = true;
                break;
            }
        }
        if(found){
            int swapleft = i-1;
          //  std::cout<<nums[swapleft]<<std::endl;

            while(nums[swapleft] < nums[i]){
                i++;
                if(i == size)
                    break;
            }
            i--;
          //  std::cout<<nums[i]<<std::endl;

            swap(nums[swapleft], nums[i]);
            sort(nums.begin()+swapleft+1,nums.end());
        }else{
            sort(nums.begin(), nums.end());
        }
    }
};
#endif /* nextPermutation_hpp */
