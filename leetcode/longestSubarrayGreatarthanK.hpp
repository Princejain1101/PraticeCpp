//
//  longestSubarrayGreatarthanK.hpp
//  leetcode
//
//  Created by Prince Jain on 6/29/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef longestSubarrayGreatarthanK_hpp
#define longestSubarrayGreatarthanK_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int longestSubarrayGreaterThanK(vector<int>& nums, int k) {
        int start=0;
        int n= (int)nums.size();
        map<int, int> greater;
        int maxlen=0;
        bool found=false;
        for(int i=0; i<n; i++){
            if(nums[i]>k){
                found=true;
                if(greater.size()==0){
                    greater[nums[i]]=1;
                }else if(greater.find(nums[i])==greater.end()){
                    pair<int,int> g = *greater.begin();
                    greater.clear();
                    int val = g.first;
                    int count = g.second;
                    while(count>0 && start < i){
                        if(nums[start]==val)
                            count--;
                        start++;
                    }
                    greater[nums[i]]=1;
                }else{
                    greater[nums[i]]++;
                }
            }
            if(found) maxlen = max(maxlen, i-start+1);
        }
        return maxlen;
    }
};
void test1(){
    Solution s;
    vector<int> nums({8, 5, 10, 10, 8});
    int k = 9;
    cout<<s.longestSubarrayGreaterThanK(nums, k)<<endl;
}
#endif /* longestSubarrayGreatarthanK_hpp */
