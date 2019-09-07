//
//  canTransforms.hpp
//  leetcode
//
//  Created by Prince Jain on 6/21/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef canTransforms_hpp
#define canTransforms_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
//    bool _canTransformUtil(string start, string end, int i){
//        if(i>=start.size() || i<0){
//            if(start == end) return true;
//            else return false;
//        }
////        cout<<"checking: "<<i<<", start: "<<start<<endl;
//        bool result = false;
//        if(start[i] == 'R'){
//            if(i < start.size()-1){
//                if(start[i+1] == 'X'){
//                    string newStart = start;
//                    swap(newStart[i],newStart[i+1]);
//                    result = result || _canTransformUtil(newStart, end, i+1);
//                    int j=i;
//                    while(j>=0){
//                        if(newStart[j]!='X')
//                            break;
//                        j--;
//                    }
//                    if(j<0) result = result || _canTransformUtil(newStart, end, j);
//                    else
//                    if(newStart[j]=='R') result = result || _canTransformUtil(newStart, end, j);
//                }
//            }
//        }
//        if(start[i] == 'L'){
//            if(i>0){
//                if(start[i-1]=='X'){
//                    string newStart = start;
//                    swap(newStart[i-1], newStart[i]);
//                    result = result || _canTransformUtil(newStart, end, i-1);
//                    int j=i;
//                    while(j<start.size()){
//                        if(newStart[j]!='X')
//                            break;
//                        j++;
//                    }
//                    if(j<start.size()) result = result || _canTransformUtil(newStart, end, j);
//                    else
//                    if(newStart[j]=='L') result = result || _canTransformUtil(newStart, end, j);
//
//                }
//            }
//        }
//        i++;
//        while(i<start.size()){
//            if(start[i]!='X')
//                break;
//            i++;
//        }
//        result = result || _canTransformUtil(start, end, i);
//        return result;
//    }
    void _replace(string &s, string c, string r){
        while(s.find(c) != string::npos){
            s.replace(s.find(c),1,r);
        }
    }
public:
//    bool canTransform(string start, string end) {
//        if(start.size() != end.size())
//            return false;
//        int i=0;
//        while(i<start.size()){
//            if(start[i] != 'X')
//                break;
//            i++;
//        }
//        return _canTransformUtil(start, end, i);
//    }
    bool canTransform(string start, string end){
        if(count(start.begin(), start.end(),'X') != count(end.begin(), end.end(),'X')) return false;
        if(count(start.begin(), start.end(),'R') != count(end.begin(), end.end(),'R')) return false;
        if(count(start.begin(), start.end(),'L') != count(end.begin(), end.end(),'L')) return false;
        int count1=0;
        int count2=0;
        for(int i=0; i<start.size(); i++){
            if(start[i]=='R') count1++;
            if(end[i]=='R') count2++;
            if(count2 > count1) return false;
        }
        count1=0; count2=0;
        for(int i=0; i<start.size(); i++){
            if(start[i]=='L') count1++;
            if(end[i]=='L') count2++;
            if(count2 < count1) return false;
        }
        _replace(start,"X","");
        _replace(end,"X","");
        if( start == end)
            return true;
        else
            return false;
    }
};
void test1(){
    Solution s;
    cout<<s.canTransform("RXXLRXRXL", "XRLXXRRLX")<<endl;
}
void test2(){
    Solution s;
    cout<<s.canTransform("XLXRRXXRXX", "LXXXXXXRRR")<<endl;
}
void test3(){
    Solution s;
    cout<<s.canTransform("XXXXXXRXXLXXRXXXRXXX", "RXXLXXXRXXXXXXRXXXXX")<<endl;
}
void test4(){
    Solution s;
    cout<<s.canTransform("XXXRXXXXRXXLXRXXXXXXRXXXXLXXXX", "XXXXXXXRRLXXXXXXXXXRRLXXXXXXXX")<<endl;
}

#endif /* canTransforms_hpp */



