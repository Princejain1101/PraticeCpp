//
//  findOrder.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findOrder_hpp
#define findOrder_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef multimap<int,int> maptype;
class Solution {
    vector<int> _getseq(maptype &nb, int course, vector<bool> & done, vector<bool>& cycle){
        std::cout<<"course: "<<course<<"cycle: "<<cycle[course]<<endl;
        vector<int>ret;
        if(cycle[course]){
            ret.push_back(-1);
            std::cout<<"returning"<<endl;
            return ret;
        }
        if(done[course])
            return ret;
        done[course]=true;
        if(nb.find(course) == nb.end()){
            ret.push_back(course);
            return ret;
        }
        cycle[course]=true;
        pair<maptype::iterator, maptype::iterator> range;
        range = nb.equal_range(course);
        for(maptype::iterator it = range.first; it != range.second; it++){
            vector<int> seq = _getseq(nb, it->second, done, cycle);
            for(auto &k:seq){
                if(k==-1){
                    cout<<"returning-2: "<<course<<endl;
                    vector<int> r;
                    r.push_back(-1);
                    return r;
                }
                ret.push_back(k);
            }
        }
        cycle[course]=false;
        ret.push_back(course);
        return ret;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        maptype nb;
        for(auto &i:prerequisites){
            nb.insert(pair<int,int>(i[0],i[1]));
        }
        vector<bool> done(numCourses,false);
        vector<bool> cycle(numCourses,false);
        for(int i=0; i<numCourses; i++){
            vector<int> seq;
            if(done[i]==false){
                seq = _getseq(nb,i,done,cycle);
            }
            for(auto &k:seq){
                if(k==-1)
                    return vector<int>();
                ret.push_back(k);
            }
        }
        return ret;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> prerequisites({{1,0},{2,0},{3,1},{3,2}});
    vector<int> res = s.findOrder(4, prerequisites);
    for(auto &i:res){
        std::cout<<i<<" ";
    }
    cout<<endl;
}
void test2(){
    Solution s;
    vector<vector<int>> prerequisites({{1,0}});
    vector<int> res = s.findOrder(2, prerequisites);
    for(auto &i:res){
        std::cout<<i<<" ";
    }
    cout<<endl;
}
void test3(){
    Solution s;
    vector<vector<int>> prerequisites({{1,0},{2,0},{3,1},{3,2},{0,1}});
    vector<int> res = s.findOrder(4, prerequisites);
    for(auto &i:res){
        std::cout<<i<<" ";
    }
    cout<<endl;
}
void test4(){
    Solution s;
    vector<vector<int>> prerequisites({{1,0},{0,1}});
    vector<int> res = s.findOrder(2, prerequisites);
    for(auto &i:res){
        std::cout<<i<<" ";
    }
    cout<<endl;
}

#endif /* findOrder_hpp */
