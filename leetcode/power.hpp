//
//  power.hpp
//  leetcode
//
//  Created by Prince Jain on 6/30/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef power_hpp
#define power_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>
using namespace std;
class Solution {
public:
    int power(int x, int y) {
        int result = 1;
        while(y>0){
            if(y&1){
                result = result*x;
            }
            y=y>>1;
            x = x*x;
        }
        return result;
    }
    int powerRec(int x, int y){
        if(y==0)
            return 1;
        int result=1;
        if(y&1){
            result = x;
        }
        return result*powerRec(x*x, y>>1);
    }
    int powermod(int x, int y, int p) {
        int result = 1;
        x = x%p;
        while(y>0){
            if(y&1){
                result = result*x;
            }
            result = result%p;
            y=y>>1;
            x = (x*x)%p;
        }
        return result;
    }
};
void test1(){
    Solution s;
    cout<<s.power(2,5)<<endl;
    cout<<s.powerRec(2,5)<<endl;
    cout<<s.powermod(2, 5, 13)<<endl;
}
#endif /* power_hpp */
