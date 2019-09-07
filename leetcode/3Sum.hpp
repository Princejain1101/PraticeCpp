//
//  3Sum.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef _Sum_hpp
#define _Sum_hpp

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // nlogn + n**2
        sort(nums.begin(), nums.end()); // nlogn
        set<vector<int>> uniquetriplets;
        for(int i=0; i<nums.size(); i++){  // n
            vector<int> triplet;
            triplet.push_back(nums[i]);
            std::cout<<"i:"<<nums[i]<<std::endl;
            int sum = -nums[i];
            int j=i+1;
            int k=(int)nums.size()-1;
            while(j<k){  // n
                int localsum = nums[j] + nums[k];
                std::cout<<"j:"<<nums[j]<<" ";
                std::cout<<"k:"<<nums[k]<<std::endl;
                if( localsum == sum){
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    uniquetriplets.insert(triplet);
                    triplet.clear();
                    triplet.push_back(-sum);
                    j++;
                }else if(localsum > sum){
                    k--;
                }else{
                    j++;
                }
            }
        }
        return vector<vector<int>>(uniquetriplets.begin(), uniquetriplets.end());
    }
};
#endif /* _Sum_hpp */
