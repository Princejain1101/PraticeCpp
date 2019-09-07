//
//  nextClosestTime.hpp
//  leetcode
//
//  Created by Prince Jain on 6/9/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef nextClosestTime_hpp
#define nextClosestTime_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
class Solution {
    int _getNext(int lower, int upper, vector<int> &digits){
        sort(digits.begin(),digits.end());
        for(auto &d:digits){
            int temp = (lower/10)*10 + d;
            if(temp > lower && temp < upper){
                return temp;
            }
        }
        for(auto &d:digits){
            int temp = d*10 + digits[0]%10;
            if(temp > lower && temp < upper){
                return temp;
            }
        }
        return -1;
    }
    string _convertToTwoDigits(int x){
        return to_string(x/10)+to_string(x%10);
    }
public:
    string nextClosestTime(string time) {
        auto pos = time.find(":");
        string h = time.substr(0,pos);
        string m = time.substr(pos+1,2);
        int hours = stoi(h);
        int minutes = stoi(m);
        std::cout<<hours<<":"<<minutes<<endl;
        vector<int> digits({hours/10, hours%10, minutes/10, minutes%10});
        sort(digits.begin(), digits.end());
        for(auto &d:digits){
            std::cout<<d<<" ";
        }
        std::cout<<std::endl;
        string c = to_string(digits[0]);

        int nextminutes = _getNext(minutes, 60, digits);
        std::cout<<"nextminutes:"<<nextminutes<<std::endl;
        if(nextminutes != -1){
            return _convertToTwoDigits(hours)+ ":" + _convertToTwoDigits(nextminutes);
        }
        int nexthours = _getNext(hours, 24, digits);
        std::cout<<"nexthours:"<<nexthours<<std::endl;
        if(nexthours != -1){
            return _convertToTwoDigits(nexthours)+ ":" + c+c;//_convertToTwoDigits(minutes);
        }
        //string c = to_string(digits[0]);
        return c+c+":"+c+c;
    }
};
#endif /* nextClosestTime_hpp */
