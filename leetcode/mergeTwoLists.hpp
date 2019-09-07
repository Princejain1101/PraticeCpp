//
//  mergeTwoLists.hpp
//  leetcode
//
//  Created by Prince Jain on 6/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef mergeTwoLists_hpp
#define mergeTwoLists_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
};
ListNode* createList(const vector<int> &vec){
    ListNode* list=nullptr;
    if(vec.size()==0)
        return list;
    list = new ListNode(vec[0]);
    auto next = list;
    for(int i=1; i<vec.size(); i++){
        auto v = vec[i];
        auto temp = new ListNode(v);
        next->next = temp;
        next = next->next;
    }
    return list;
}
void printList(ListNode* list){
    while(list != nullptr){
        std::cout<<list->val;
        if(list->next !=nullptr){
            std::cout<<"->";
        }
        list = list->next;
    }
    std::cout<<std::endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* sol=nullptr;
        ListNode* node=nullptr;
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode* next = nullptr;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                next = l1;
                l1 = l1->next;
            }else{
                next = l2;
                l2 = l2->next;
            }
            if(sol==nullptr){
                sol = next;
                node = next;
            }else{
                node->next = next;
                node = next;
            }
        }
        if(l1 != nullptr){
            next->next = l1;
        }
        if(l2 != nullptr){
            next->next = l2;
        }
        return sol;
    }
};
void test1(){
    Solution s;
    vector<int> vec1({1,2,4});
    vector<int> vec2({1,3,4});
    ListNode* l1 = createList(vec1);
    ListNode* l2 = createList(vec2);
    printList(l1);
    printList(l2);
    ListNode* sol = s.mergeTwoLists(l1, l2);
    printList(sol);
}

#endif /* mergeTwoLists_hpp */
