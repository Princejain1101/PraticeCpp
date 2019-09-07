//
//  rotate.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef rotate_hpp
#define rotate_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int circle = (int)matrix.size();
        int iS = -1;
        int iF = circle;
        int jS = -1;
        int jF = circle;
        while(circle >1){
            iS++;
            iF--;
            jS++;
            jF--;
            int steps = circle -1;
            for(int step=0; step<steps; step++){
                int buffer = matrix[iS][jS];
                int buffer2;
                //top
                for(int k=0; k< steps; k++){
                    buffer2 = matrix[iS][jS+k+1];
                    matrix[iS][jS+k+1] = buffer; //matrix[iS+k][jS];
                    buffer = buffer2;
                }
    //            for(auto &v: matrix){
    //                for(auto & e: v){
    //                    std::cout<<e<<" ";
    //                }
    //                std::cout<<std::endl;
    //            }
                //right
                for(int k=0; k< steps; k++){
                    buffer2 = matrix[iS+k+1][jF];
                    matrix[iS+k+1][jF] = buffer; //matrix[iS+k][jS];
                    buffer = buffer2;
                }
    //            for(auto &v: matrix){
    //                for(auto & e: v){
    //                    std::cout<<e<<" ";
    //                }
    //                std::cout<<std::endl;
    //            }
                //bottom
                for(int k=0; k< steps; k++){
                    buffer2 = matrix[iF][jF-k-1];
                    matrix[iF][jF-k-1] = buffer; //matrix[iS+k][jS];
                    buffer = buffer2;
                }
    //            for(auto &v: matrix){
    //                for(auto & e: v){
    //                    std::cout<<e<<" ";
    //                }
    //                std::cout<<std::endl;
    //            }
                //left
                for(int k=0; k< steps; k++){
                    buffer2 = matrix[iF-k-1][jS];
                    matrix[iF-k-1][jS] = buffer; //matrix[iS+k][jS];
                    buffer = buffer2;
                }
    //            for(auto &v: matrix){
    //                for(auto & e: v){
    //                    std::cout<<e<<" ";
    //                }
    //                std::cout<<std::endl;
    //            }
            }
            circle -= 2;
        }
    }
};
#endif /* rotate_hpp */
