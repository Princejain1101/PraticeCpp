//
//  sortArray012.hpp
//  leetcode
//
//  Created by Prince Jain on 7/1/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef sortArray012_hpp
#define sortArray012_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    void sortArrays012(vector<int>& nums) {
        int n = (int)nums.size();
        int low=-1;
        int high=n;
        int i=0;
        while(i<high){
            if(nums[i]<1){
                low++;
                swap(nums[i],nums[low]);
            }
            if(nums[i]>1){
                high--;
                swap(nums[i],nums[high]);
            }
            if(nums[i]==1 || i==low){
                i++;
            }
        }
    }
};
void test1(){
    Solution s;
//    vector<int> nums({0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1});
    vector<int> nums({2, 1, 0, 0, 1,0});

    s.sortArrays012(nums);
    for(auto &i:nums) cout<<i<<", ";
    cout<<endl;
}

#endif /* sortArray012_hpp */
