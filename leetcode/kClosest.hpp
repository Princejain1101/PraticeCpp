//
//  kClosest.hpp
//  leetcode
//
//  Created by Prince Jain on 6/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef kClosest_hpp
#define kClosest_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
class comparator{
    public:
    bool operator()(const pair<int,int> a, const pair<int,int> b) const{
        return a.first < b.first;
    }
};
class Solution {
    int _getDist(const vector<int> &point){
        if(point.size()<2)
            return 0;
        return point[0]*point[0] + point[1]*point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> heap;//[](const pair<int,int> a, const pair<int,int> b)const { return a.first < b.first;})>
        for(int i=0; i<K && i<points.size(); i++){
            heap.push(pair<int,int>(_getDist(points[i]),i));
        }
        for(int i=K; i<points.size(); i++){
            int dist = _getDist(points[i]);
            if(dist < (heap.top()).first){
                heap.pop();
                heap.push(pair<int,int>(dist,i));
            }
        }
        while(!heap.empty()){
            int i = (heap.top()).second;
            ret.push_back(points[i]);
            heap.pop();
        }
        return ret;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> points = {
        {1,3},{-2,2}
    };
    for(auto &v:s.kClosest(points, 1)){
        for(auto &e:v){
            std::cout<<e<<" ";
        }
        std::cout<<std::endl;
    }
}
void test2(){
    Solution s;
    vector<vector<int>> points = {
        {3,3},{5,-1},{-2,4}
    };
    for(auto &v:s.kClosest(points, 2)){
        for(auto &e:v){
            std::cout<<e<<" ";
        }
        std::cout<<std::endl;
    }
}
#endif /* kClosest_hpp */
