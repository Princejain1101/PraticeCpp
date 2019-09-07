//
//  copyRandomList.hpp
//  leetcode
//
//  Created by Prince Jain on 6/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef copyRandomList_hpp
#define copyRandomList_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
struct Node{
    int val;
    Node* next;
    Node* random;
    Node() {}
    Node(int _val, Node* _next = nullptr, Node* _random=nullptr){
        val = _val;
        next = _next;
        random = _random;
    }
};
Node* createList(const vector<int> &vec){
    Node* list=nullptr;
    if(vec.size()==0)
        return list;
    list = new Node(vec[0],nullptr,nullptr);
    auto next = list;
    for(int i=1; i<vec.size(); i++){
        auto v = vec[i];
        auto temp = new Node(v);
        next->next = temp;
        next = next->next;
    }
    return list;
}
void printList(Node* list){
    while(list != nullptr){
        std::cout<<list->val;
        if(list->random != nullptr)
            std::cout<<"("<<list->random->val<<")";
        std::cout<<"->";
        list = list->next;
    }
    std::cout<<std::endl;
}
class Solution {
    Node* _createNode(Node* orig, map<Node*,Node*> &mapping){
        if(orig==nullptr)
            return nullptr;
        if(mapping.find(orig) != mapping.end()){
            return mapping[orig];
        }
        Node* newNode = new Node(orig->val);
        mapping.insert(pair<Node*,Node*>(orig,newNode));
        newNode->next = _createNode(orig->next, mapping);
        newNode->random = _createNode(orig->random, mapping);
        return newNode;
    }
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mapping;
        return _createNode(head, mapping);
    }
};
void test1(){
    Solution s;
    Node* n1 = new Node(1,nullptr,nullptr);
    Node* n2 = new Node(2,nullptr,nullptr);
    n1->next = n2;
    n1->random = n2;
    n2->random = n2;
    printList(n1);
    printList(n2);
    Node* sol = s.copyRandomList(n1);
    printList(sol);
}


#endif /* copyRandomList_hpp */
