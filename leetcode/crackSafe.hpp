//
//  crackSafe.hpp
//  leetcode
//
//  Created by Prince Jain on 6/16/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef crackSafe_hpp
#define crackSafe_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <math.h>

using namespace std;
class Solution {
    int _getNumber(string s, int n){
        int number=0;
        int multiplier=1;
        for(int i=1; i<=n; i++){
            int index = (int)s.size()-i;
            int digit = (s[index]-'0')*multiplier;
            number += digit;
            multiplier *= 10;
        }
        return number;
    }
    string _getSubstr(string s, int n){
        return s.substr(s.size()-n,n);
    }
    string _crackSafeUtil(int n, int k, set<string> safecode, string s, int count){
        if(s.size()>=n){
//            int number = _getNumber(s, n);
            string sub = _getSubstr(s, n);
            cout<<"s: "<<s<<", sub: "<<sub<<endl;
            cout<<"safecode size: "<<safecode.size()<<", count: "<<count<<endl;
//            if(safecode[number]==true){
            if(safecode.find(sub)!=safecode.end()){
                cout<<"returning null"<<endl;
                string tmp="";
                return tmp;
            }
            else{
                cout<<"setting safecode "<<sub<<endl;
//                safecode[number]=true;
                safecode.insert(sub);
                count--;
            }
            if(count==0)
                return s;
        }
//        cout<<"s: "<<s<<endl;
        int minLength=INT_MAX;
        string sret="";
        for(int i=0; i<k; i++){
            cout<<"s: "<<s<<", k: "<<i<<endl;
            string st = s;
            string stemp = _crackSafeUtil(n, k, safecode, st.append(1,(i+'0')), count);
            if(stemp.size() != 0){
                if(stemp.size() < minLength){
                    sret = stemp;
                    minLength = (int)stemp.size();
                    if(stemp.size()==pow(k,n))
                        return stemp;
                }
            }
        }
        cout<<"found min s: "<<s<<endl;
        return sret;
    }
public:
    string crackSafe(int n, int k) {
        int count = pow(k,n);
        set<string> safecode;
        string s="";
        return _crackSafeUtil(n, k, safecode, s, count);
    }
};
void test1(){
    Solution s;
    cout<<s.crackSafe(2, 2)<<endl;
}
void test2(){
    Solution s;
    cout<<s.crackSafe(1, 2)<<endl;
}
void test3(){
    Solution s;
    cout<<s.crackSafe(1, 9)<<endl;
}
void test4(){
    Solution s;
    cout<<s.crackSafe(2, 4)<<endl;
}

#endif /* crackSafe_hpp */
