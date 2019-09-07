//
//  licenseKeyFormatting.hpp
//  leetcode
//
//  Created by Prince Jain on 6/7/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef licenseKeyFormatting_hpp
#define licenseKeyFormatting_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string retS;
        int countK=0;
        for(std::string::reverse_iterator it = S.rbegin(); it != S.rend(); it++){
            if(*it != '-'){
                countK++;
                retS += std::toupper(*it);
            }
            if(countK == K){
                retS += "-";
                countK = 0;
            }
        }
        std::reverse(retS.begin(), retS.end());
        // removing end dashes
        int erase_length = 0;
        for(auto & s: retS){
            if(s != '-') break;
            if(s == '-') erase_length++;
        }
        if(erase_length) retS.erase(0,erase_length);
        return retS;
    }
};
#endif /* licenseKeyFormatting_hpp */
