//
//  medianInaStream.h
//  leetcode
//
//  Created by Prince Jain on 7/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef medianInaStream_h
#define medianInaStream_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
class Solution {
public:
    int getMedianInsetion(int e, vector<int>& sortedvec){
        sortedvec.push_back(e);
        for(int i= (int)sortedvec.size()-1; i>0; i--){
            if(sortedvec[i] < sortedvec[i-1]){
                swap(sortedvec[i], sortedvec[i-1]);
            }else{
                break;
            }
        }
        int s = (int)sortedvec.size();
//        cout<<"size: "<<s<<endl;
        if(s%2==0){
            return (sortedvec[(s-1)/2] + sortedvec[s/2])/2;
        }else{
            return sortedvec[s/2];
        }
    }
    int getMedian(int e, int& m, priority_queue<int>& maxh, priority_queue<int, vector<int>, greater<int>>& minh) {
        int maxl = (int)maxh.size();
        int minl = (int)minh.size();
        if(maxl - minl ==1){
            if(e < m){
                minh.push(maxh.top());
                maxh.pop();
                maxh.push(e);
            }else{
                minh.push(e);
            }
            m = (maxh.top() + minh.top() )/2;
        }else if( maxl == minl){
            if(e<m){
                maxh.push(e);
                m = maxh.top();
            }else{
                minh.push(e);
                m = minh.top();
            }
        }else if(minl - maxl == 1){
            if(e < m){
                maxh.push(e);
            }else{
                maxh.push(minh.top());
                minh.pop();
                minh.push(e);
            }
            m = (maxh.top() + minh.top() )/2;
        }
        return m;
    }
};
void test1(){
    Solution s;
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> vec({5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4});
    vector<int> sortedvec;
    int m = INT_MAX;
    for(auto &i: vec){
        m = s.getMedian(i, m, maxh, minh);
        cout<<m<< " "<< s.getMedianInsetion(i, sortedvec)<<endl;
    }
}

#endif /* medianInaStream_h */
