//
//  oddEvenJump.hpp
//  leetcode
//
//  Created by Prince Jain on 6/6/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef oddEvenJump_hpp
#define oddEvenJump_hpp


#include <stdio.h>
#include <vector>
#include <map>


using namespace std;

class Solution {
    std::map<int, int> IndexMap;
    int _findMinI(int a){
        auto it = IndexMap.find(a);
        it++;
        if(it != IndexMap.end()){
            return it->second;
        }
        return -1;
    }
    // get maximum value in right, less than or equal to a.
    int _findMaxI(int a){
        auto it = IndexMap.find(a);
        if(it == IndexMap.begin())
            return -1;
        it--;
        return it->second;

    }
public:
    int oddEvenJumps(vector<int>& A) {
        int size = (int)A.size();
        int maxI = size-1;
        int minI = size-1;
        IndexMap[A[size-1]] = size-1;
        vector<bool> oddSuccess(size,false);
        vector<bool> evenSuccess(size,false);

        oddSuccess[size-1] = true;
        evenSuccess[size-1] = true;
        
        int totalCount = 1;
        for(int i=size-2; i>=0; i--){
//            std::cout<<"ele: "<<A[i]<<endl;
//            std::cout<<"findmaxI: "<<_findMaxI(A[i])<<", findminI: "<<_findMinI(A[i])<<std::endl;
            auto it = IndexMap.find(A[i]);
            if(it != IndexMap.end()){
              //  std::cout<<"found A[i]: "<<A[i]<<std::endl;
                evenSuccess[i] = oddSuccess[it->second];
                oddSuccess[i] = evenSuccess[it->second];
            }else{
                IndexMap[A[i]] = i;
                int j;
                if((j = _findMaxI(A[i])) != -1){
                    maxI = j;
                    evenSuccess[i] = oddSuccess[maxI];
                }
                if((j = _findMinI(A[i])) != -1){
                    minI = j;
                    oddSuccess[i] = evenSuccess[minI];
                }
            }
           
            IndexMap[A[i]] = i;
            if(oddSuccess[i]){
                totalCount++;
            }
//            std::cout<<"oddsuccess[i]: "<<oddSuccess[i]<<std::endl;
//            std::cout<<"evenSuccess[i]: "<<evenSuccess[i]<<std::endl;
//            std::cout<<"totalCount: "<<totalCount<<std::endl;
        }
        return totalCount;
    }
};

#endif /* oddEvenJump_hpp */
