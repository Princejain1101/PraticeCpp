//
//  findNextSparse.hpp
//  leetcode
//
//  Created by Prince Jain on 6/30/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findNextSparse_hpp
#define findNextSparse_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int findNextSparse(int input) {
        int x = input;
        vector<int> bits;
        while(x !=0){
            bits.push_back(x&1);
            x = x>>1;
        }
        bits.push_back(0);
        int n = (int)bits.size();
        int setZero = 0;
        for(int i=0; i<n; i++){
//            cout<<bits[i]<<endl;
            if(setZero){
                if(setZero==1){
                    if(bits[i]==1){
                        setZero=2;
                        bits[i]=0;
                        bits[i-1]=0;
                    }else{
                        setZero=0;
                    }
                }else{
                    if(bits[i]==1){
                        bits[i]=0;
                    }else{
                        bits[i]=1;
                        setZero=1;
                    }
                }
            }else{
                if(bits[i]==1){
                    setZero = 1;
                }
            }
        }
        int result=0;
        int shifting=0;
        for(auto &i:bits){
            result |= i<<shifting;
            shifting++;
        }
        return result;
    }
};
void test1(){
    Solution s;
    cout<<s.findNextSparse(44)<<endl;
}
#endif /* findNextSparse_hpp */
