//
//  peakIndexInMountainArray.hpp
//  leetcode
//
//  Created by Prince Jain on 6/19/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef peakIndexInMountainArray_hpp
#define peakIndexInMountainArray_hpp

// 0,1,2,3,5,7,9,10,21,1

#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
    int _peakIndexUtil(vector<int>& A, int start, int end){
        if(end-start==2){ // 3 elements left
            return start+1;
        }
        int mid = (start+end)/2;
        if(A[mid] > A[mid-1] && A[mid] > A[mid+1])
            return mid;
        if(A[mid] > A[mid-1] && A[mid] < A[mid+1])
            return _peakIndexUtil(A, mid, end);
        return _peakIndexUtil(A, start, mid);
    }
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return _peakIndexUtil(A, 0, (int)A.size()-1);
    }
};
void test1(){
    Solution s;
    vector<int> A({0,2,1,0});
    cout<<s.peakIndexInMountainArray(A)<<endl;
}
void test2(){
    Solution s;
    vector<int> A({0,1,0});
    cout<<s.peakIndexInMountainArray(A)<<endl;
}
#endif /* peakIndexInMountainArray_hpp */
