//
//  reverseInteger.hpp
//  leetcode
//
//  Created by Prince Jain on 6/19/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef reverseInteger_hpp
#define reverseInteger_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    vector<int> _getdigits(int x){
        vector<int> digits;
        // if(x<0)
        //     x *= -1;
        while(x%10==0){
            x=x/10;
        }
        while(x!=0){
            int digit = x - (x/10)*10;
            if(digit<0)
                digit *= -1;
            digits.push_back(digit);
            x = x/10;
        }
        return digits;
    }
public:
    int reverse(int x) {
        if(x==0)
            return 0;
        bool pos = x>0?true:false;
        vector<int> digits = _getdigits(x);
        std::reverse(digits.begin(), digits.end());
        int result=0;
        if(pos){
            int multiplier=1;
            for(int i=0; i<digits.size(); i++){
                int temp = digits[i];
                //                cout<<temp<<endl;
                if(INT_MAX/multiplier < temp )
                    return 0;
                temp = temp*multiplier;
                if(INT_MAX - result <temp){ // checking overflow
                    return 0;
                }else{
                    result = result + temp;
                }
                if(i == digits.size()-1)
                    break;
                if(INT_MAX/multiplier < 10)
                    return 0;
                multiplier *= 10;
            }
            return result;
        }else{
            int multiplier=1;
            for(int i=0; i<digits.size(); i++){
                int temp = -digits[i];
                // cout<<"temp: "<<temp<<endl;
                if(INT_MIN/multiplier > temp )
                    return 0;
                
                temp = temp*multiplier;
                // cout<<"temp: "<<temp<<endl;
                if(INT_MIN - result > temp){ // checking overflow
                    //                    if(result + temp == INT_MIN && i == digits.size()-1){
                    //                        return INT_MIN;
                    //                    }
                    return 0;
                }else{
                    result = result + temp;
                }
                // cout<<"result: "<<result<<endl;
                if(i == digits.size()-1)
                    break;
                if(INT_MAX/multiplier < 10)
                    return 0;
                multiplier *= 10;
            }
            return result;
        }
    }
};
void test1(){
    Solution s;
    cout<<s.reverse(120)<<endl;
}
void test2(){
    Solution s;
    cout<<s.reverse(-123)<<endl;
}
void test3(){
    Solution s;
    cout<<s.reverse(1534236469)<<endl;
}
#endif /* reverseInteger_hpp */
