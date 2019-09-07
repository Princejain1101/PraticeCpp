//
//  multiply.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef multiply_hpp
#define multiply_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Solution {
    string _sum(string num1, string num2){
        string ret="";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int length1 = (int)num1.size() == 0 ? 0 : (int)num1.size();
        int length2 = (int)num2.size() == 0 ? 0 : (int)num2.size();
//        std::cout<<"num1: "<<num1<<", len: "<<length1<<std::endl;
//        std::cout<<"num2: "<<num2<<", len: "<<length2<<std::endl;

        int i = (length1 > length2) ? length2 : length1;
        int c = 0;
        for(int j=0; j<i; j++){
            int sum = c + (num1[j] - '0') + (num2[j] - '0');
            c = sum/10;
            char s = sum%10 + '0';
            ret += s;
        }
        while(i < length1){
            int sum = c + (num1[i] - '0');
            c = sum/10;
            char s = sum%10 + '0';
            ret += s;
            i++;
        }
        while(i < length2){
            int sum = c + (num2[i] - '0');
            c = sum/10;
            char s = sum%10 + '0';
            ret += s;
            i++;
        }
        if(c != 0){
            char s = c + '0';
            ret += s;
        }
        reverse(ret.begin(),ret.end());
//        std::cout<<ret<<", len:"<<ret.size()<<std::endl;
        return ret;
    }
    string _multipyUnit(string num, int x){
        string ret = "";
        if(x==0){
            return ret;
        }
        if(x == 1){
            return num;
        }
        ret = num;
        while(x > 1){
            ret = _sum(ret, num);
            x--;
        }
//        std::cout<<ret<<", len:"<<ret.size()<<std::endl;

        return ret;
    }
public:
    string multiply(string num1, string num2) {
        string ret ="";
        if(num1 == "0" || num2 == "0")
            return "0";
        int zeros = 0;
        reverse(num2.begin(), num2.end());
        for(auto &n: num2){
            string subsum = _multipyUnit(num1, n-'0');
//            std::cout<<subsum<<", len:"<<subsum.size()<<std::endl;

            for(int i=0; i<zeros; i++)
                subsum += '0';
//            std::cout<<subsum<<", len:"<<subsum.size()<<std::endl;

//            std::cout<<"return: "<<ret<<std::endl;
            ret = _sum(subsum,ret);
//            std::cout<<"stepreturn: "<<ret<<std::endl;
            zeros++;
        }
        return ret;
        
    }
    string testmultiplyUnit(string num, int x){
        return _multipyUnit(num, x);
    }
    string testSum(string num1, string num2){
        return _sum(num1, num2);
    }
    string multiply2(string num1, string num2){
        if(num1.size()==0 || num2.size()==0){
            return "0";
        }
        int n1 = (int)num1.size();
        int n2 = (int)num2.size();
        vector<int> result(n1+n2,0);
        int i_n1=0; int i_n2=0;
        for(int i=n1-1; i>=0; i--){
            int op1 = num1[i] - '0';
            int carry=0;
            i_n2=0;
            for(int j=n2-1; j>=0; j--){
                int op2 = num2[j] - '0';
                int sum = op1*op2 + carry + result[i_n1 + i_n2];
                carry = sum/10;
                result[i_n1 + i_n2] = sum%10;
                i_n2++;
            }
            if(carry>0){
                result[i_n1+i_n2] += carry;
                cout<<"carry: "<<carry<<", result: "<<result[i_n1+i_n2]<<endl;
            }
            i_n1++;
        }
        int i = (int)result.size()-1;
        while(i>=0 && result[i]==0){
            i--;
        }
        string s = "";
        for(;i>=0; i--){
            s = s + to_string(result[i]);
        }
        return s;
    }
};
void test1(){
    Solution s;
    cout<<s.multiply("1235421415454545454545454544", "1714546546546545454544548544544545")<<endl;
    cout<<s.multiply2("1235421415454545454545454544", "1714546546546545454544548544544545")<<endl;
}

#endif /* multiply_hpp */
