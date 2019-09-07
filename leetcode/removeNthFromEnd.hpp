//
//  removeNthFromEnd.hpp
//  leetcode
//
//  Created by Prince Jain on 6/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef removeNthFromEnd_hpp
#define removeNthFromEnd_hpp

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
    ListNode* _removeNode(ListNode* head, ListNode* node){
        if(node->next !=nullptr){
            node->next = node->next->next;
        }
        return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)
            return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        int length=0;
        int i=0;
        while(fast!=nullptr){
            std::cout<<"fast:";
            printList(fast);
            if(fast->next==nullptr){
                length = i*2 + 1;
                fast=nullptr;
            }else if(fast->next->next ==nullptr){
                length = i*2 + 2;
                fast = nullptr;
            }else{
                slow = slow->next;
                fast = fast->next->next;
                i += 1;
            }
        }
        std::cout<<"length: "<<length<<std::endl;
        int k = length - n;
        std::cout<<"k:"<<k<<", i:"<<i<<std::endl;
        int start = 0;
        if(k>i){
            start=i;
        }else{
            start=0;
            slow=head;
        }
        std::cout<<"start: "<<start<<std::endl;
        std::cout<<"slow val: "<<slow->val<<std::endl;

        for(int j=start; j<k-1; j++){
            slow = slow->next;
        }
        std::cout<<"slow val: "<<slow->val<<std::endl;
        if(k==0){
            head = head->next;
        }else{
            head = _removeNode(head,slow);
        }
        return head;
    }
};
void test1(){
    Solution s;
    vector<int> vec({1,2,3,4,5});
    ListNode* list = createList(vec);
    printList(list);
    ListNode* sol = s.removeNthFromEnd(list, 2);
    printList(sol);
}
void test2(){
    Solution s;
    vector<int> vec({1,2});
    ListNode* list = createList(vec);
    printList(list);
    ListNode* sol = s.removeNthFromEnd(list, 2);
    printList(sol);
}
#endif /* removeNthFromEnd_hpp */
