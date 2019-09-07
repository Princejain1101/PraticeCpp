//
//  disjointset.hpp
//  leetcode
//
//  Created by Prince Jain on 6/29/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef disjointset_hpp
#define disjointset_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;
class Solution {
    int _findTopManager(unordered_map<int,int> &manager, int emp){
        while(manager.find(emp) != manager.end()){
            emp = manager[emp];
        }
        return emp;
    }
public:
    bool isPeer(unordered_map<int,int> &manager, int emp1, int emp2) {
        int man1 = emp1;
        while(manager.find(man1) != manager.end()){
            man1 = manager[man1];
            if(emp2 == man1) return false;
        }
        int man2 = emp2;
        while(manager.find(man2) != manager.end()){
            man2 = manager[man2];
            if(emp1 == man2) return false;
        }
        if(man1==man2) return true;
        return false;
    }
    bool isManager(unordered_map<int,int> &manager, int emp1, int emp2){
        int man = emp1;
        while(manager.find(man) != manager.end()){
            man = manager[man];
            if(man == emp2) return true;
        }
        return false;
    }
};
void test1(){
    Solution s;
    unordered_map<int,int> manager;
    manager.insert({2,1});
    manager.insert({3,2});
    manager.insert({1,4});
    manager.insert({5,1});
    manager.insert({6,5});
    cout<<s.isManager(manager, 3, 4)<<endl;
    cout<<s.isPeer(manager, 3, 6)<<endl;

}
#endif /* disjointset_hpp */
