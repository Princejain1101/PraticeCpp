//
//  insertIntervals.hpp
//  leetcode
//
//  Created by Prince Jain on 6/18/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef insertIntervals_hpp
#define insertIntervals_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int _getInsertIndex(vector<vector<int>> &intervals, vector<int>& newInterval, int start, int end, int index){
        if(end<start){
            return start;
        }
        if(end == start){
            return newInterval[index] > intervals[start][index] ? start+1 : start;
        }
        
        int mid = (start+end)/2;
        if(intervals[mid][index]==newInterval[index]){
            return mid+1;
        }
        if(newInterval[index] > intervals[mid][index])
            return _getInsertIndex(intervals, newInterval, mid+1, end, index);
        return _getInsertIndex(intervals, newInterval, start, mid-1, index);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int low = _getInsertIndex(intervals, newInterval, 0, (int)intervals.size()-1, 0);
        int high = _getInsertIndex(intervals, newInterval, 0, (int)intervals.size()-1, 1);
        cout<<"low: "<<low<<endl;
        cout<<"high: "<<high<<endl;
        vector<int> localInterval(2);
        if(high >= low){
            if(low>0){
                if(intervals[low-1][1] >= newInterval[0]){
                    localInterval[0]  = intervals[--low][0];
                }else{
                    localInterval[0] = newInterval[0];
                }
//                localInterval[0] = intervals[low-1][1] >= newInterval[0] ? intervals[low-1][0]: newInterval[0];
            }else{
                localInterval[0] = newInterval[0];
            }
            if(high>0){
                if(intervals[high-1][1] > newInterval[1])
                    localInterval[1] = intervals[high-1][1];
                else{
                    localInterval[1] = newInterval[1];
                }
            }else{
                localInterval[1] = newInterval[1];
            }
        }else{
            high=low;
            localInterval[1] = intervals[low-1][1];
            if(intervals[low-1][1] >= newInterval[0]){
                localInterval[0]  = intervals[--low][0];
            }else{
                localInterval[0] = newInterval[0];
            }
        }
        cout<<localInterval[0]<<" "<<localInterval[1]<<endl;
        vector<vector<int>> result;
//        if(intervals[low-1][1] >= newInterval[0]){
//            low--;
//        }
        cout<<"low:"<<low<<", high:"<<high<<endl;
        for(int i=0; i<low; i++){
            cout<<"i:"<<i<<endl;
            result.push_back(intervals[i]);
        }
        result.push_back(localInterval);
        for(int i=high; i<intervals.size(); i++){
            if(intervals[i][0]<=localInterval[1]){
                result[result.size()-1][1] = intervals[high][1];
                continue;
            }
            result.push_back(intervals[i]);
        }
        return result;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> intervals({{1,3},{6,9}});
    vector<int> newInterval({2,5});
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for(auto &vec:result){
        cout<<"("<<vec[0]<<","<<vec[1]<<"),";
    }
    cout<<endl;
}
void test2(){
    Solution s;
    vector<vector<int>> intervals({{1,2},{3,5},{6,7},{8,10},{12,16}});
    vector<int> newInterval({4,8});
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for(auto &vec:result){
        cout<<"("<<vec[0]<<","<<vec[1]<<"),";
    }
    cout<<endl;
}
void test3(){
    Solution s;
    vector<vector<int>> intervals({{1,5}});
    vector<int> newInterval({2,3});
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for(auto &vec:result){
        cout<<"("<<vec[0]<<","<<vec[1]<<"),";
    }
    cout<<endl;
}
void test4(){
    Solution s;
    vector<vector<int>> intervals({{1,5}});
    vector<int> newInterval({6,8});
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for(auto &vec:result){
        cout<<"("<<vec[0]<<","<<vec[1]<<"),";
    }
    cout<<endl;
}
void test5(){
    Solution s;
    vector<vector<int>> intervals({{0,5},{8,9}});
    vector<int> newInterval({3,4});
    vector<vector<int>> result = s.insert(intervals, newInterval);
    for(auto &vec:result){
        cout<<"("<<vec[0]<<","<<vec[1]<<"),";
    }
    cout<<endl;
}
#endif /* insertIntervals_hpp */
