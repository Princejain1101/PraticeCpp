//
//  numberOfPatters.hpp
//  leetcode
//
//  Created by Prince Jain on 6/17/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef numberOfPatters_hpp
#define numberOfPatters_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;
struct edge{
    int a;
    int b;
    edge(int _a, int _b):a(_a),b(_b){}
    bool operator==(const edge & e1) const{
        if( (e1.a== a) && (e1.b == b)){
            return true;
        }else{
            return false;
        }
    }
};
namespace std{
    template<> struct hash<edge>{
        uint64_t operator()(const edge &p) const noexcept{
            return ((uint64_t)p.a)<<32 | (uint64_t)p.b;
        }
    };
}

class Solution {
public:
    bool _isValid(int a, int b){
        if(a==-1){
            return true;
        }
        if(a==1){
            if(b==2 || b==4 || b==5|| b==8 || b==6)
                return true;
            else return false;
        }
        if(a==2){
            if(b==1 || b==3 || b==4 || b==5 || b==6 || b==7 || b==9)
                return true;
            else return false;
        }
        if(a==3){
            if(b==2 || b==4 || b==5|| b==6 || b==8)
                return true;
            else return false;
        }
        if(a==4){
            if(b==1 || b==2 || b==3 || b==5 || b==7 || b==8 || b==9)
                return true;
            else return false;
        }
        if(a==5){
            if(b==1 || b==2 || b==3 || b==4 || b==6 || b==7 || b==8 || b==9)
                return true;
            else return false;
        }
        if(a==6){
            if(b==1 || b==2 || b==3 || b==5 || b==7 || b==8 || b==9)
                return true;
            else return false;
        }
        if(a==7){
            if(b==2 || b==4 || b==5|| b==8 || b==6)
                return true;
            else return false;
        }
        if(a==8){
            if(b==1 || b==3 || b==4 || b==5 || b==6 || b==7 || b==9)
                return true;
            else return false;
        }
        if(a==9){
            if(b==2 || b==4 || b==5|| b==8 || b==6)
                return true;
            else return false;
        }
        return true;
    }
    int _numberOfPatterns(int m, int n, int a, int b, int count, unordered_set<edge> edges){
//        if(count != 1){
        if(!(_isValid(a, b) || _isValid(b, a))){
            return 0;
        }
//        }
        if(edges.find(edge(a,b)) != edges.end() || edges.find(edge(b,a)) != edges.end())
            return 0;
        
        if(count > n){
            return 0;
        }
        edges.insert(edge(a,b));
        int ret=0;
        if(count >=m){
            ret++;
        }
        for(int i=1; i<=9; i++){
            int temp = _numberOfPatterns(m, n, i, a, count+1, edges);
//            cout<<"i: "<<i<<", a: "<<a<<", temp: "<<temp<<endl;
            ret += temp;
        }
        return ret;
    }
    int numberOfPatterns(int m, int n) {
        int ret=0;
        unordered_set<edge> edges;
        for(int i=1; i<=9; i++){
            ret += _numberOfPatterns(m, n, i, -1, 1, edges);
        }
        return ret;
    }
};
void test1(){
    Solution s;
    cout<<s.numberOfPatterns(1,1)<<endl;
}
void test2(){
    Solution s;
    cout<<s.numberOfPatterns(1,3)<<endl;
}

#endif /* numberOfPatters_hpp */
