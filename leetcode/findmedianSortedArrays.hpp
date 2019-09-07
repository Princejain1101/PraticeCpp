//
//  findmedianSortedArrays.hpp
//  leetcode
//
//  Created by Prince Jain on 6/18/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findmedianSortedArrays_hpp
#define findmedianSortedArrays_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    double _returnOneVec(vector<int> vec){
        if(vec.size()==0)
            return 0;
//        if(vec.size()==1)
//            return vec[0];
//        if(vec.size()==2)
//            return ((double)vec[0]+ (double)vec[1])/2;
//        if(vec.size()==3)
//            return vec[1];
        int size =(int)vec.size();
        if(size%2==1){
            return (double)vec[size/2];
        }else{
            return ((double)vec[(size-1)/2]+(double)vec[(size)/2]) /2;
        }
//        return 0.0;
    }
    double _medianLessthan3(vector<int>vec1, vector<int> vec2){
//        cout<<"vec1"<<endl;
//        printVec(vec1);
//        cout<<"vec2"<<endl;
//        printVec(vec2);
        if(vec1.size()==0)
            return _returnOneVec(vec2);
        if(vec2.size()==0)
            return _returnOneVec(vec1);
        if(vec1.size()==1){
            int size = (int)vec2.size();
            for(auto it = vec2.begin(); it != vec2.end(); it++){
                if(*it >= vec1[0]){
                    vec2.insert(it, vec1[0]);
                    break;
                }
            }
            if(vec2.size()==size)
                vec2.push_back(vec1[0]);
//            cout<<vec2[0]<<" "<<vec2[1]<<" "<<vec2[2]<<endl;
            cout<<"returning one vec1"<<endl;

            return _returnOneVec(vec2);
        }
        if(vec2.size()==1){
            int size = (int)vec1.size();
            for(auto it = vec1.begin(); it != vec1.end(); it++){
                if(*it >= vec2[0]){
                    vec1.insert(it, vec2[0]);
                    break;
                }
            }
            if(vec1.size()==size)
                vec1.push_back(vec2[0]);
//            cout<<vec1[0]<<" "<<vec1[1]<<" "<<vec1[2]<<endl;
//            cout<<"returning one vec1"<<endl;
            return _returnOneVec(vec1);
        }
        return 0.0;
    }
    double _getMedian(vector<int> vec){
        int size = (int)vec.size();
        if(size%2==0){
            return ((double)vec[size/2]+(double)vec[(size-1)/2])/2;
        }
        return (double)vec[size/2];
    }
    void printVec(vector<int> vec){
        for(auto &i:vec){
            cout<<i<<" ";
        }
        cout<<endl;
    }
public:
    double _findMedianUtil(vector<int> vec1, vector<int> vec2, bool even){
        if(vec1.size() ==0 ||  vec2.size() ==0){
            return _medianLessthan3(vec1, vec2);
        }
        if(vec1.size() + vec2.size() ==2 && even){
            return _medianLessthan3(vec1, vec2);
        }
        if(vec1.size() + vec2.size() ==3 && !even){
//            cout<<"3 odd elements"<<endl;
            return _medianLessthan3(vec1, vec2);
        }
        double median1 = vec1[(vec1.size()-1)/2];//_getMedian(vec1);
        double median2 = vec2[(vec2.size()-1)/2];//_getMedian(vec2);
        vector<int> newvec1(vec2);
        vector<int> newvec2;
        if(median2 <= median1){
            int i=0;
            for(i=0; i<vec1.size()/2; i++){
                newvec2.push_back(vec1[i]);
            }
            if(vec1.size()%2==1)
                newvec2.push_back(vec1[i]);
        }else{
            int i=(int)vec1.size()/2;
            for(; i<vec1.size(); i++){
                newvec2.push_back(vec1[i]);
            }
        }
        printVec(newvec1);
        printVec(newvec2);
        return _findMedianUtil(newvec1, newvec2, even);
        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool even=true;
        if((nums1.size()%2 ==0 && nums2.size()%2==1) || (nums1.size()%2 ==1 && nums2.size()%2==0))
            even =false;
        return _findMedianUtil(nums1, nums2, even);
    }
};
// http://www.drdobbs.com/parallel/finding-the-median-of-two-sorted-arrays/240169222?pgno=2
void test1(){
    Solution s;
    vector<int> nums1({5,7,9,11,15});
    vector<int> nums2({1,8});
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
void test2(){
    Solution s;
    vector<int> nums1({1,3});
    vector<int> nums2({2});
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
void test3(){
    Solution s;
    vector<int> nums1({1,2});
    vector<int> nums2({3,4});
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
void test4(){
    Solution s;
    vector<int> nums1({1,2,3,4,7});
    vector<int> nums2({0,5,6,9});
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
void test5(){
    Solution s;
    vector<int> nums1({});
    vector<int> nums2({1,2,3,4});
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
void test6(){
    Solution s;
    vector<int> nums1({3});
    vector<int> nums2({-2,-1});
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
void test7(){
    Solution s;
    vector<int> nums1({1,2});
    vector<int> nums2({-1,3});
    cout<<s.findMedianSortedArrays(nums1, nums2)<<endl;
}
#endif /* findmedianSortedArrays_hpp */
