//
//  list.h
//  leetcode
//
//  Created by Prince Jain on 7/4/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef list_h
#define list_h

#include <iostream>
#include <vector>

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
        std::cout<<list->val<<"->";
        list = list->next;
    }
    std::cout<<std::endl;
}

#endif /* list_h */
