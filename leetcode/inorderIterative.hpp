//
//  inorderIterative.hpp
//  leetcode
//
//  Created by Prince Jain on 6/29/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef inorderIterative_hpp
#define inorderIterative_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        cout<<root->val<<endl;
        inorder(root->right);
    }
    void inorderIterStack(TreeNode* root) {
        if(root==nullptr)return;
        stack<TreeNode*> nodestack;
        TreeNode* curr = root;
        while(!nodestack.empty() || curr != nullptr){
            while(curr != nullptr){
                nodestack.push(curr);
                curr = curr->left;
            }
            curr = nodestack.top();
            nodestack.pop();
            cout<<curr->val<<endl;
            curr = curr->right;
        }
    }

    void inorderNoStackWithThreading(TreeNode* root){
        TreeNode* prev;
        TreeNode* curr;
        curr = root;
        while(curr != nullptr){
            if(curr->left==nullptr){
                cout<<curr->val<<endl;
                curr = curr->right;
            }else{
                prev = curr->left;
                while(prev->right != nullptr && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }else{
                    prev->right = nullptr;
                    cout<<curr->val<<endl;
                    curr = curr->right;
                }
            }
        }
    }
    void inorderNoStackNoThreadingWithParent(TreeNode* root){
        
    }
    void postorder(TreeNode* root){
        if(root==nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<endl;
    }
    void postorder2stack(TreeNode* root){
        if(root == nullptr)return;
        stack<TreeNode*> nodestack, auxstack;
        nodestack.push(root);
        
        while(!nodestack.empty()){
            TreeNode* temp = nodestack.top();
            nodestack.pop();
            auxstack.push(temp);
            if(temp->left) nodestack.push(temp->left);
            if(temp->right) nodestack.push(temp->right);
        }
        while(!auxstack.empty()){
            TreeNode* temp = auxstack.top();
            auxstack.pop();
            cout<<temp->val<<endl;
        }
    }
    void preorder(TreeNode* root){
        if(root==nullptr)return;
        cout<<root->val<<endl;
        preorder(root->left);
        preorder(root->right);
    }
    void preorderIter(TreeNode* root){
        if(root==nullptr)return ;
        stack<TreeNode*> nodestack;
        nodestack.push(root);
        while(!nodestack.empty()){
            TreeNode* temp = nodestack.top();
            nodestack.pop();
            cout<<temp->val<<endl;
            if(temp->right) nodestack.push(temp->right);
            if(temp->left) nodestack.push(temp->left);
        }
    }
};
void test1(){
    /* Constructed binary tree is
               1
            /   \
          2      3
        /  \
       4    5
     */
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout<<"Inorder"<<endl;
    cout<<"iterstack"<<endl;
    s.inorderIterStack(root);
    cout<<"recursive"<<endl;
    s.inorder(root);
    cout<<"inordernostacking with threading"<<endl;
    s.inorderNoStackWithThreading(root);
    
    cout<<"Postorder"<<endl;
    cout<<"recursive"<<endl;
    s.postorder(root);
    cout<<"postorder2stack"<<endl;
    s.postorder2stack(root);
    
    cout<<"Preorder"<<endl;
    cout<<"recursive"<<endl;
    s.preorder(root);
    cout<<"iterative"<<endl;
    s.preorderIter(root);
}
#endif /* inorderIterative_hpp */
