//
//  isAnagram.hpp
//  leetcode
//
//  Created by Prince Jain on 6/18/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef isAnagram_hpp
#define isAnagram_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    void _fillMap(map<char,int> &map, string s){
        for(auto &c:s){
            if(map.find(c)==map.end()){
                map[c]=1;
            }else{
                map[c]++;
            }
        }
    }
public:
    bool isAnagram(string s, string t) {
        map<char,int> maps;
        map<char,int> mapt;
        _fillMap(maps, s);
        _fillMap(mapt, t);
        if(maps.size() != mapt.size())
            return false;
        auto its = maps.begin();
        auto itt = mapt.begin();
        for(int i=0; i<maps.size(); i++){
            if(its->first != itt->first || its->second !=itt->second)
                return false;
            its++;
            itt++;
        }
        return true;
    }
};
void test1(){
    Solution s;
    cout<<s.isAnagram("anagram", "nagaram")<<endl;
}
void test2(){
    Solution s;
    cout<<s.isAnagram("cat", "rat")<<endl;
}
#endif /* isAnagram_hpp */
