//
//  addTwoNumbersList.hpp
//  leetcode
//
//  Created by Prince Jain on 6/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef addTwoNumbersList_hpp
#define addTwoNumbersList_hpp

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
        std::cout<<list->val<<"->";
        list = list->next;
    }
    std::cout<<std::endl;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret=nullptr;
        ListNode* next=nullptr;
        int carry = 0;
        
        while(l1 != nullptr || l2 != nullptr || carry>0){
            int a=0;
            int b=0;
            if(l1!= nullptr)
                a = l1->val;
            if(l2 != nullptr)
                b = l2->val;
            int sum = a + b + carry;
            int val = sum%10;
            carry = sum/10;
            ListNode* temp = new ListNode(val);
            if(next == nullptr){
                next = temp;
                ret = next;
            }else{
                next->next = temp;
                next = temp;
            }
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return ret;
    }
};
void test1(){
    Solution s;
    vector<int> vec1({2,4,3});
    vector<int> vec2({5,6,4});
    ListNode* l1 = createList(vec1);
    ListNode* l2 = createList(vec2);
    printList(l1);
    printList(l2);
    ListNode* sol = s.addTwoNumbers(l1, l2);
    printList(sol);
}
void test2(){
    Solution s;
    vector<int> vec1({5});
    vector<int> vec2({5});
    ListNode* l1 = createList(vec1);
    ListNode* l2 = createList(vec2);
    printList(l1);
    printList(l2);
    ListNode* sol = s.addTwoNumbers(l1, l2);
    printList(sol);
}
#endif /* addTwoNumbersList_hpp */
