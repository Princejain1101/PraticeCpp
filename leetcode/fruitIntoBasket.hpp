//
//  fruitIntoBasket.hpp
//  leetcode
//
//  Created by Prince Jain on 6/7/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef fruitIntoBasket_hpp
#define fruitIntoBasket_hpp

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int max = 0;
        int startOne = 0;
        int endOne = 0;
        int range = 0;
        vector<int> elements(2,-1);
        elements[1] = tree[0];
        range = 1;
        max = 1;
        for(int i = 1; i < tree.size(); i++){
//            std::cout<<"ele0: "<<elements[0]<<", ele1: "<<elements[1]<<std::endl;
//            std::cout<<"startOne: "<<startOne<<", endOne: "<<endOne<<std::endl;
            if(elements[0] == tree[i]){
                std::swap(elements[0], elements[1]);
                startOne = endOne + 1;
                endOne = i-1;
                range++;
            }else if(elements[1] == tree[i] ){
                range++;
            }else{
                if(elements[0] != -1){
                    startOne = endOne + 1;
                }
                endOne = i-1;
                range = i - startOne + 1;
                
                elements[0] = elements[1];
                elements[1] = tree[i];
            }
            max = (range > max) ? range : max;
//            std::cout<<"startOne: "<<startOne<<", endOne: "<<endOne<<std::endl;
//            std::cout<<"range: "<<range<<std::endl;

        }
        return max;
    }
};

#endif /* fruitIntoBasket_hpp */
