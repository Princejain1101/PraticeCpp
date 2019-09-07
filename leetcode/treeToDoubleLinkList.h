//
//  treeToDoubleLinkList.h
//  leetcode
//
//  Created by Prince Jain on 7/14/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef treeToDoubleLinkList_h
#define treeToDoubleLinkList_h

#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    TreeNode* succPred(TreeNode* root, TreeNode* head){
        static TreeNode* pred=nullptr;
        if(root==nullptr) return nullptr;
        
//        cout<<root->val<<endl;
        
        succPred(root->left, head);
        if(pred==nullptr) head->right = root;
        root->left = pred;
        if(pred) pred->right = root;
        pred = root;
        TreeNode* right = succPred(root->right, head);
        if(right)
            return right;
        else
            return root;
        
    }
    TreeNode* treeToDoublyList(TreeNode* root) {
        TreeNode* head = new TreeNode(-1);
        TreeNode* last = succPred(root, head);
        last->right = head->right;
        head->right->left = last;
        return head->right;
    }
};
void test1(){
    Solution s;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(5);
    
    TreeNode* node = s.treeToDoublyList(root);
    TreeNode* curr = node;
    for(int i=0; i<5; i++){
        cout<<curr->val<<endl;
        curr=curr->right;
    }
    curr = node->left;
    for(int i=0; i<5; i++){
        cout<<curr->val<<endl;
        curr = curr->left;
    }
    
}


#endif /* treeToDoubleLinkList_h */
