//
//  plusOne.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef plusOne_hpp
#define plusOne_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        vector<int> ret;
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            int sum = c + *it;
            int q = sum%10;
            c = sum/10;
            ret.push_back(q);
        }
        if(c){
            ret.push_back(c);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
#endif /* plusOne_hpp */
