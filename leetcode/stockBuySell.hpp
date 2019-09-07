//
//  stockBuySell.hpp
//  leetcode
//
//  Created by Prince Jain on 6/30/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef stockBuySell_hpp
#define stockBuySell_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int stockBuySellMaxProfit(vector<int>& nums){
        int n = (int)nums.size();
        if(n<2) return 0;
        int sum=0;
        int i=0;
        while(i<n-1){
            while(i<n-1 && nums[i+1]<=nums[i])
                i++;
            if(i>=n-1)
                break;
            int buy = i++;
            
            while(i<n && nums[i-1] <= nums[i])
                i++;
            i--;
            sum += nums[i]-nums[buy];
        }
        return sum;
    }
};
void test1(){
    Solution s;
    vector<int> nums({100, 180, 260, 310, 40, 535, 695 });
    cout<<s.stockBuySellMaxProfit(nums)<<endl;
}
#endif /* stockBuySell_hpp */
