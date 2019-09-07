//
//  candy.hpp
//  leetcode
//
//  Created by Prince Jain on 6/19/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef candy_hpp
#define candy_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1]+1;
            }
            cout<<candies[i]<<endl;
        }
        for(int i=(int)ratings.size()-2; i>=0; i--){
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
                candies[i] = candies[i+1]+1;
            }
            cout<<candies[i]<<endl;
        }
        int total=0;
        for(auto &cd:candies){
            total +=cd;
        }
        return total;
    }
};
void test1(){
    Solution s;
    vector<int> ratings({1,0,2});
    cout<<s.candy(ratings)<<endl;
}
void test2(){
    Solution s;
    vector<int> ratings({1,2,2});
    cout<<s.candy(ratings)<<endl;
}
void test3(){
    Solution s;
    vector<int> ratings({1,2,87,87,87,2,1});
    cout<<s.candy(ratings)<<endl;
}
#endif /* candy_hpp */
