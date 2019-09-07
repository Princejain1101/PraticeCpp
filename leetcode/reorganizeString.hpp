//
//  reorganizeString.hpp
//  leetcode
//
//  Created by Prince Jain on 6/25/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef reorganizeString_hpp
#define reorganizeString_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
struct comparator{
    bool operator()(const pair<char,int>& a, const pair<char,int>& b) const {
        if(a.second > b.second) return true;
        else return false;
    }
};

class Solution {
public:
    string reorganizeString(string S) {
        if(S.size()<2) return S;
        map<char,int> charcountmap;
        for(auto &c:S){
            if(charcountmap.find(c) == charcountmap.end()){
                charcountmap.insert(pair<char,int>(c,1));
            }else{
                charcountmap[c]++;
            }
        }
//        cout<<"size: "<<charcountmap.size()<<endl;
        if(charcountmap.size()==1) return "";
        multiset<pair<char,int>, comparator> charcount(charcountmap.begin(),charcountmap.end());
//        cout<<"size: "<<charcount.size()<<endl;
        string result;
        while(charcount.size()>=2){
            pair<char,int> a = *(charcount.begin());
//            cout<<a.first<<endl;
            charcount.erase(charcount.begin());
            pair<char,int> b = *(charcount.begin());
            charcount.erase(charcount.begin());
//            cout<<"size: "<<charcount.size()<<endl;
            while(a.second >0 && b.second>0){
                result.push_back(a.first);
                a.second--;
                result.push_back(b.first);
                b.second--;
//                cout<<result<<endl;
            }
//            cout<<a.second<<" "<<b.second<<endl;
            if(a.second>0) {
//                cout<<"inserting a"<<endl;
                charcount.insert(a);
            }
            if(b.second>0) {
//                cout<<"inserting b"<<endl;
                charcount.insert(b);
            }
//            cout<<charcount.size()<<endl;
        }
        if(charcount.size()==1) {
            if(charcount.begin()->second != 1 || charcount.begin()->first == result[result.size()-1]) return "";
            else{
                result.push_back(charcount.begin()->first);
            }
        }
        return result;
    }
};
void test1(){
    Solution s;
    cout<<s.reorganizeString("aaabbccddddddee")<<endl;
}
void test2(){
    Solution s;
    cout<<s.reorganizeString("vvvlo")<<endl;
}
#endif /* reorganizeString_hpp */
