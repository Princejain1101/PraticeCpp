//
//  maxDistToClosest.hpp
//  leetcode
//
//  Created by Prince Jain on 6/11/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef maxDistToClosest_hpp
#define maxDistToClosest_hpp

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ret=0;
        int count=0;
        int temp=0;
        for(int i=0; i<seats.size(); i++){
            if(seats[i]==0){
                count++;
                continue;
            }
            std::cout<<"count: "<<count<<", i: "<<i<<std::endl;
            // condition on starting 0's
            if(i == count){
                temp = count;
            }else{
                temp = (count+1) / 2;
            }
            count = 0;
            std::cout<<"temp: "<<temp<<std::endl;
            ret = ret > temp ? ret : temp;
            std::cout<<"ret: "<<ret<<std::endl;
        }
        if(seats[seats.size()-1]==0){
            temp = count;
        }
        ret = ret > temp ? ret : temp;

        return ret;
    }
};
void test1(){
    Solution s;
    vector<int> seats({1,0,0,0,1,0,1});
    std::cout<<(s.maxDistToClosest(seats) == 2)<<std::endl;

}
void test2(){
    Solution s;
    vector<int> seats({1,0,0,0});
    std::cout<<(s.maxDistToClosest(seats) == 3)<<std::endl;
    
}

#endif /* maxDistToClosest_hpp */
