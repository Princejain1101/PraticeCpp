//
//  solveEquation.hpp
//  leetcode
//
//  Created by Prince Jain on 6/29/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef solveEquation_hpp
#define solveEquation_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
int _findNumber(string s){
    if(s.size()==0) return 1;
    int ret = 0;
    for(int i=0; i<s.size(); i++){
        ret = ret*10 + s[i]-'0';
    }
    return ret;
}
class Solution {
    void _getXC(string s, int &X, int &C){
        int x=0;
        int c=0;
        bool prevpos=true;
        size_t n = s.find_first_of("+-");
        int start=0;
        while(n != string::npos){
            if(n==0){
                if(s[n]=='-') prevpos=false;
                else prevpos = true;
                s = s.substr(n+1);
                n = s.find_first_of("+-");
                continue;
            }
            if(s[n-1]=='x'){
                if(prevpos)
                    x += _findNumber(s.substr(start,n-1-start));
                else
                    x -= _findNumber(s.substr(start,n-1-start));
            }else{
                if(prevpos)
                    c += _findNumber(s.substr(start,n-start));
                else
                    c -= _findNumber(s.substr(start,n-start));
            }
            if(s[n]=='-') prevpos=false;
            else prevpos = true;
            s = s.substr(n+1);
            n = s.find_first_of("+-");
        }
        n = s.size();
//        cout<<"n:"<<n<<endl;
        if(s[n-1]=='x'){
            if(prevpos)
                x += _findNumber(s.substr(start,n-1-start));
            else
                x -= _findNumber(s.substr(start,n-1-start));
        }else{
            if(prevpos)
                c += _findNumber(s.substr(start,n-start));
            else
                c -= _findNumber(s.substr(start,n-start));
        }
        X = x;
        C = c;
    }
public:
    string solveEquation(string equation) {
        size_t eq = equation.find('=');
        string lhs = equation.substr(0,eq);
        cout<<"lhs: "<<lhs;
        string rhs = equation.substr(eq+1);
        cout<<", rhs: "<<rhs<<endl;
        int lhsX=0;
        int lhsC=0;
        _getXC(lhs, lhsX, lhsC);
        cout<<lhsX<<", "<<lhsC<<endl;
        int rhsX=0;
        int rhsC=0;
        _getXC(rhs, rhsX, rhsC);
        cout<<rhsX<<", "<<rhsC<<endl;
        int Xcoeff = lhsX - rhsX;
        int ConsCoeff = rhsC - lhsC;
        if(Xcoeff==0 && ConsCoeff==0) return "Infinite Solutions";
        if(Xcoeff == 0) return "No Solution";
        int sol = ConsCoeff/Xcoeff;
        return "x="+to_string(sol);
    }
};
void test1(){
    Solution s;
    cout<<s.solveEquation("x+5-3+x=6+x-2")<<endl;
}
void test2(){
    Solution s;
    cout<<s.solveEquation("x=x")<<endl;
}
void test3(){
    Solution s;
    cout<<s.solveEquation("2x=x")<<endl;
}
void test4(){
    Solution s;
    cout<<s.solveEquation("2x+3x-6x=x+2")<<endl;
}
void test5(){
    Solution s;
    cout<<s.solveEquation("x=x+2")<<endl;
}
void test6(){
    Solution s;
    cout<<s.solveEquation("-x=-1")<<endl;
}
#endif /* solveEquation_hpp */
