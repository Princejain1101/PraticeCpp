//
//  mergeKLists.hpp
//  leetcode
//
//  Created by Prince Jain on 6/11/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef mergeKLists_hpp
#define mergeKLists_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

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
typedef pair<int,ListNode*> qnode;

struct customcompare{
public:
    bool operator() (const qnode &a, const qnode &b) const {
        return a.first > b.first;
    }
};
typedef priority_queue<qnode,vector<qnode>, customcompare> customeq;

void printHeap(customeq pq){
    while(!pq.empty()){
        std::cout<<pq.top().first<<",";
        pq.pop();
    }
    std::cout<<std::endl;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* list=nullptr;
        customeq minheap;
        //priority_queue<int, vector<int>, greater<int>> test;
        for(auto &list: lists){
            if(list != nullptr)
                minheap.push(pair<int,ListNode*>(list->val,list));
        }
        printHeap(minheap);
        if(!minheap.empty()){
            list = (minheap.top()).second;
            minheap.pop();
            std::cout<<"pop: ";
            printHeap(minheap);

            if(list->next != nullptr){
                ListNode* temp = list->next;
                minheap.push(pair<int,ListNode*>(temp->val,temp));
                std::cout<<"push: ";
                printHeap(minheap);
            }
            printList(list);
        }else{
            return nullptr;
        }
        ListNode* next = list;
        while(!minheap.empty()){
            auto temp = minheap.top().second;
            minheap.pop();
            std::cout<<"pop: ";
            printHeap(minheap);

            if(temp->next != nullptr){
                ListNode* temp2 = temp->next;
                minheap.push(pair<int,ListNode*>(temp2->val,temp2));
                std::cout<<"push: ";
                printHeap(minheap);
            }
            next->next = temp;
            printList(list);
            next = temp;
        }
        return list;
    }
};
void test1(){
    Solution s;
    vector<int> list1({1,4,5});
    vector<int> list2({1,3,4});
    vector<int> list3({2,6});
    
    vector<ListNode*> listvec({createList(list1), createList(list2), createList(list3)});
    ListNode* out = s.mergeKLists(listvec);
    printList(out);
}
#endif /* mergeKLists_hpp */
