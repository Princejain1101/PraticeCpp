//
//  reverseLinkList.hpp
//  leetcode
//
//  Created by Prince Jain on 6/27/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef reverseLinkList_hpp
#define reverseLinkList_hpp

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
    ListNode* _reverseLinkListUtil(ListNode* node, ListNode* &head){
        if(node->next == nullptr){
            head = node;
            return node;
        }
        ListNode* temp = _reverseLinkListUtil(node->next, head);
        node->next = nullptr;
        temp->next = node;
        return node;
    }
    ListNode* _reverseLinkListUtilAtK(ListNode* node, ListNode* &prev, ListNode* &next, int k, int count){
        cout<<"node-val: "<<node->val<<endl;
        if(node==nullptr) return nullptr;
        if(node->next == nullptr){
            cout<<"returning nullplace: "<<node->val<<endl;
            prev = node;
            next = nullptr;
            return node;
        }
        ListNode* prevNode;
        if(count<k-1){
            prevNode = _reverseLinkListUtilAtK(node->next, prev, next, k, count+1);
            cout<<"returning prevNode: "<<prevNode->val<<endl;
            prevNode->next = node;
            if(count==0){
                node->next = next;
            }
        }else{
            prev = node;
            ListNode* next2=nullptr;
            ListNode* prev2 = nullptr;
            _reverseLinkListUtilAtK(node->next, prev2, next2, k, 0);
//            cout<<"head:"<<prev2->val<<endl;
            next = prev2;
        }
        cout<<"returning:"<<node->val<<endl;
        return node;
    }
public:
    ListNode* reverseLinkList(ListNode* list) {
        ListNode* result;
        if(list == nullptr) return nullptr;
        _reverseLinkListUtil(list, result);
        return result;
    }
    ListNode* reverseLinkListIter(ListNode* list){
        if(list==nullptr) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = list;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseLinkListIterAtK(ListNode* list, int k){
        if(list==nullptr) return nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = list;
        ListNode* next = nullptr;
        int count=0;
        while(curr != nullptr && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(curr != nullptr){
            list->next = reverseLinkListIterAtK(curr, k);
        }
        return prev;
    }
    ListNode* reverseLinkListAtK(ListNode* list, int k){
        ListNode* result = nullptr;
        if(list==nullptr) return nullptr;
        ListNode* next = nullptr;
        _reverseLinkListUtilAtK(list, result, next, k, 0);
        return result;
    }
};
void test1(){
    Solution s;
    vector<int> nums({1,2,3,4,5});
    ListNode* list = createList(nums);
    printList(list);
//    ListNode* result = s.reverseLinkList(list);
//    printList(result);
//    ListNode* result2 = s.reverseLinkListIter(list);
//    printList(result2);
//    ListNode* result2 = s.reverseLinkListIterAtK(list, 2);
//    printList(result2);
    ListNode* result2 = s.reverseLinkListAtK(list, 2);
    printList(result2);

}

#endif /* reverseLinkList_hpp */
