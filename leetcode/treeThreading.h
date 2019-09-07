//
//  treeThreading.h
//  leetcode
//
//  Created by Prince Jain on 7/9/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef treeThreading_h
#define treeThreading_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    void populateInorderQueue(TreeNode* root, queue<TreeNode*>& q){
        if(root == nullptr) return;
        if(root->left != nullptr)
            populateInorderQueue(root->left, q);
        q.push(root);
        if(root->right != nullptr)
            populateInorderQueue(root->right, q);
    }
    void createThreaded(TreeNode* root, queue<TreeNode*>& q){
        if(root==nullptr) return;
        if(root->left != nullptr)
            createThreaded(root->left, q);
        q.pop();
        if(root->right != nullptr)
            createThreaded(root->right, q);
        else{
            if(q.size()>0){
                root->right = q.front();
                root->threaded=true;
            }
        }
    }
    // without queue... space efficient
    TreeNode* createThreaded(TreeNode* root){
        if(root==nullptr) return nullptr;
        if(root->left != nullptr){
            TreeNode* rightmost = createThreaded(root->left);
            rightmost->right = root;
            rightmost->threaded=true;
        }
        if(root->right != nullptr){
            return createThreaded(root->right);
        }else{
            return root;
        }
    }
    TreeNode* leftMost(TreeNode* node){
        if(node==nullptr) return nullptr;
        while(node->lthreaded == false) { //nullptr){
            node = node->left;
        }
        return node;
    }
    void inorderThreaded(TreeNode* root) {
//        queue<TreeNode*> q;
//
//        populateInorderQueue(root, q);
//        createThreaded(root, q);
        
//        createThreaded(root);
        TreeNode* curr = leftMost(root);
        while(curr){
            cout<<curr->val<<endl;
            if(curr->threaded){
                curr = curr->right;
            }else{
                curr = leftMost(curr->right);
            }
        }
    }
    TreeNode* insertTheaded(TreeNode* root, int key){
//        if(root==nullptr){
//        }
        TreeNode* parent = nullptr;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->val == key){
                cout<<"already present key: "<<key<<endl;
                return root;
            }
            parent = curr;
            if(key < curr->val){
                if(curr->lthreaded==false){
                    curr = curr->left;
                }else{
                    break;
                }
            }else{
                if(curr->threaded==false){
                    curr = curr->right;
                }else{
                    break;
                }
            }
        }
        
        TreeNode* node = new TreeNode(key);
        node->lthreaded = true;//parent->lthreaded;
        node->threaded=true;

        if(parent==nullptr){
            root = node;
        }else if(key < parent->val){
            node->left = parent->left;
            node->right = parent;
            parent->left = node;
            parent->lthreaded = false;
        }else{
            node->right = parent->right;
            node->left = parent;
            parent->right = node;
            parent->threaded = false;
        }
        return root;
    }
};
void test1(){
    Solution s;
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
//
//    root->left->left = new TreeNode(4);
//    root->left->right = new TreeNode(5);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(7);
    TreeNode* root = nullptr;
    root = s.insertTheaded(root, 20);
    root = s.insertTheaded(root, 10);
    root = s.insertTheaded(root, 30);
    root = s.insertTheaded(root, 5);
    root = s.insertTheaded(root, 16);
    root = s.insertTheaded(root, 14);
    root = s.insertTheaded(root, 17);
    root = s.insertTheaded(root, 13);

    s.inorderThreaded(root);
}

#endif /* treeThreading_h */
