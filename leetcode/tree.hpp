//
//  tree.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
#define null INT_MIN
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    bool threaded=false;
    bool lthreaded=false;
    TreeNode* next;
    TreeNode* prev;
    int height;
    TreeNode():val(0),left(nullptr),right(nullptr),next(nullptr),prev(nullptr),height(0){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr),next(nullptr),prev(nullptr),height(0){}
};
TreeNode* createTree(const vector<int> &vec, int i){
    TreeNode* node=nullptr;
    if(i >=  vec.size() || vec[i]==null){
        return nullptr;
    }
    node = new TreeNode(vec[i]);
    node->left = createTree(vec, 2*i + 1);
    node->right = createTree(vec, 2*i + 2);
    return node;
}

void printTreeInorder(TreeNode* root){
    if(root == nullptr)
        return;
    printTreeInorder(root->left);
    std::cout<<root->val<<" ";
    printTreeInorder(root->right);
    
}
void printTreePreorder(TreeNode* root){
    if(root == nullptr)
        return;
    std::cout<<root->val<<" ";
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}
#endif /* tree_hpp */
