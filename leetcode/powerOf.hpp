//
//  powerOf.hpp
//  leetcode
//
//  Created by Prince Jain on 6/28/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef powerOf_hpp
#define powerOf_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>

using namespace std;
class Solution {
    bool _powerOfUtilBinary(int num, int sub, int a, int b){
//        cout<<"num: "<<num<<", a: "<<a<<", b:"<<b<<endl;
        if(a>b) return false;
        if(a==b){
            if(num/ pow(sub,a) == 1) return true;
            else return false;
        }
        int mid = (a+b)/2;
//        cout<<"mid: "<<mid<<", pow(sub,mid): "<<pow(sub,mid)<<endl;
        if((int) num / pow(sub,mid) == 1) return true;
//        cout<<"(num / pow(sub,mid)): "<<(num / pow(sub,mid))<<endl;
        if( (int)(num / pow(sub,mid)) < 1) {
            return _powerOfUtilBinary(num, sub, a, mid-1);
        }
        return _powerOfUtilBinary(num, sub, mid+1, b);
    }
public:
    bool powerOf(int num, int sub){
        if(sub==1)
            if(num==1) return true;
//        if(num/sub==1) return true;
//        if(num/sub == 0) return false;
        int a = sub;
        int i = 1;
        //a = num/sub;
        while(a<num){
//            cout<<"a:"<<a<<", sub^2: "<<(pow(sub,i))<<endl;
//            a = (int) num/pow(sub,i);
            a = a*a;
            i *= 2;
        }
//        i = i/2;
        return _powerOfUtilBinary(num, sub, i/2, i);
    }
};
void test1(){
    Solution s;
    cout<<"pow(7,8):"<<pow(7,8)<<endl;
    cout<<s.powerOf(0, 7)<<endl;
}
#endif /* powerOf_hpp */
