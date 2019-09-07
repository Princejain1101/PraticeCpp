//
//  countSmaller.hpp
//  leetcode
//
//  Created by Prince Jain on 6/19/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef countSmaller_hpp
#define countSmaller_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

//   1,2,3,3,4,6,6,8,8,8,9
using namespace std;
class Solution {
    int _insertSortedUtil(vector<int> &donesorted, int start, int end, int n){
        if(end < start){
            return start;
        }
        if(start == end){
            if(n<=donesorted[start]){
                return start;
            }else{
                return start+1;
            }
        }
        int mid = (start+end)/2;
        if(n <= donesorted[mid])
            return _insertSortedUtil(donesorted, start, mid, n);
        else
            return _insertSortedUtil(donesorted, mid+1, end, n);
    }

    int _insertInSorted(vector<int> &donesorted, int n){
        int i = _insertSortedUtil(donesorted, 0, (int)donesorted.size()-1, n);
        donesorted.insert(donesorted.begin()+i,n);
        return i;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        vector<int> numssorted(nums);
        sort(numssorted.begin(), numssorted.end());
        unordered_map<int,int> mapsorted;
        for(int i=0; i<(int)numssorted.size(); i++){
            if(mapsorted.find(numssorted[i]) == mapsorted.end()){
                mapsorted.insert(pair<int,int>(numssorted[i],i));
            }
        }
        vector<int> donesorted;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            int maxSmaller = mapsorted[n];
            int doneSmaller = _insertInSorted(donesorted, n);
            int finalSmaller = maxSmaller-doneSmaller;
            result.push_back(finalSmaller);
        }
        return result;
    }
};
void test1(){
    Solution s;
    vector<int> nums({5,2,6,1});
    vector<int> counts = s.countSmaller(nums);
    for(auto &i:counts){
        cout<<i<<" ";
    }
    cout<<endl;
}
#endif /* countSmaller_hpp */
