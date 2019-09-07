//
//  canJump.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef canJump_hpp
#define canJump_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = (int)nums.size();
        if(size==0 or size==1){
            return true;
        }
        vector<bool> reachable(size, false);
        reachable[size-1] = true;
        //bool reaching=false;
        for(int i=size-2; i>=0; i--){

            for(int j=1; j<=nums[i]; j++){
                if(i+j >= size-1){
                    reachable[i] = true;
                    break;
                    //reaching = true;
                }
                else if(reachable[i+j]==true){
                    reachable[i]=true;
                    //reaching = true;
                    break;
                }else{
                    j = j + nums[i+j];
                }
            }
        }
        return reachable[0];
    }
};

#endif /* canJump_hpp */
