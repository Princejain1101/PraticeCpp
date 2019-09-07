//
//  findKthLargest.hpp
//  leetcode
//
//  Created by Prince Jain on 6/12/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findKthLargest_hpp
#define findKthLargest_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int largest = 0;
        if(nums.size() <k){
            return 0;
        }
        priority_queue<int,vector<int>, greater<int>> maxHeap;
        for(int i=0; i<k; i++){
            maxHeap.push(nums[i]);
        }
        for(int i=k; i<nums.size(); i++){
            if(nums[i] >= maxHeap.top()){
//                std::cout<<maxHeap.top()<<std::endl;
                maxHeap.pop();
                maxHeap.push(nums[i]);
            }
        }
        largest = maxHeap.top();
        return largest;
    }
};
void test1(){
    Solution s;
    vector<int> nums({3,2,1,5,6,4});
    std::cout<<s.findKthLargest(nums, 2)<<std::endl;
}
void test2(){
    Solution s;
    vector<int> nums({3,2,3,1,2,4,5,5,6});
    std::cout<<s.findKthLargest(nums, 4)<<std::endl;
}

#endif /* findKthLargest_hpp */
