//
//  maxArea.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef maxArea_hpp
#define maxArea_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
    int _getArea(int x1, int y1, int x2, int y2){
        if(y2 > y1){
            return (x2-x1)*y1;
        }else{
            return (x2-x1)*y2;
        }
    }
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int x1 = 0;
        int x2 = (int)height.size()-1;
        while(x1 < x2){
            int left = height[x1];
            int right = height[x2];
            std::cout<<"height["<<x1<<"]:"<<left<<", height["<<x2<<"]:"<<right<<std::endl;
            int area = _getArea(x1, left, x2, right);
            std::cout<<"area:"<<area<<endl;
            max = (area > max) ? area : max;
            std::cout<<"max:"<<max<<endl;
            if(left< right){
//                x1++;
//                if(x1 >= x2)
//                    break;
                while((height[x1] <= left) && x1 < x2){
                    x1++;
                }
            }else{
//                x2--;
//                if(x1 >= x2)
//                    break;
                while((height[x2] <= right) && x1 < x2){
                    x2--;
                }
            }
        }
        return max;
    }
//    int maxArea2(
};
void test1(){
    vector<int> height({1,8,6,2,5,4,8,3,7});
    Solution s;
    cout<<s.maxArea(height)<<endl;
}
#endif /* maxArea_hpp */
