//
//  binaryTreeMaxPathSum.hpp
//  leetcode
//
//  Created by Prince Jain on 6/13/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef binaryTreeMaxPathSum_hpp
#define binaryTreeMaxPathSum_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#define null INT_MIN
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
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

class Solution {
    int _getMax(TreeNode* node, int& pathMax){
        if(node == nullptr){
            pathMax=0;
            return 0;
        }
        if(node->left ==nullptr && node->right == nullptr){
            pathMax=node->val;
            return node->val;
        }
        int leftPathMax;
        int leftMax = _getMax(node->left, leftPathMax);
        int rightPathMax;
        int rightMax = _getMax(node->right, rightPathMax);
        std::cout<<"node: "<<node->val<<" ";
        std::cout<<", leftMax: "<<leftMax<<", leftPathMax: "<<leftPathMax<<" ";
        std::cout<<", rightMax: "<<rightMax<<", rightPathMax: "<<rightPathMax<<std::endl;
        pathMax = node->val;
        if(node->left == nullptr){
            pathMax = pathMax > pathMax+rightPathMax ? pathMax : pathMax+rightPathMax;
        }else if(node->right == nullptr){
            pathMax = pathMax > pathMax+leftPathMax ? pathMax : pathMax+leftPathMax;
        }else if(leftPathMax > rightPathMax){
            pathMax = pathMax > pathMax+leftPathMax ? pathMax : pathMax+leftPathMax;
        }else{
            pathMax = pathMax > pathMax+rightPathMax ? pathMax : pathMax+rightPathMax;
        }
        int maxval = pathMax;
        if(node->left != nullptr) maxval = maxval > leftMax ? maxval : leftMax;
        if(node->right != nullptr) maxval = maxval > rightMax ? maxval : rightMax;
        if(node->left != nullptr && node->right != nullptr)
            maxval = maxval > (leftPathMax + rightPathMax + node->val) ? maxval : (leftPathMax + rightPathMax + node->val);
        return maxval;
    }
public:
    int maxPathSum(TreeNode* root) {
        int pathMax;
        return _getMax(root, pathMax);
    }
};
void test1(){
    Solution s;
    vector<int> vec({1,2,3});
    TreeNode* root = createTree(vec, 0);
    printTreeInorder(root);
    std::cout<<std::endl;
    std::cout<<s.maxPathSum(root)<<std::endl;
}
void test2(){
    Solution s;
    vector<int> vec({-10,9,20,null,null,15,7});
    TreeNode* root = createTree(vec, 0);
    printTreeInorder(root);
    std::cout<<std::endl;
    std::cout<<s.maxPathSum(root)<<std::endl;
}
void test3(){
    Solution s;
    vector<int> vec({-3});
    TreeNode* root = createTree(vec, 0);
    printTreeInorder(root);
    std::cout<<std::endl;
    std::cout<<s.maxPathSum(root)<<std::endl;
}
void test4(){
    Solution s;
    vector<int> vec({-2,-1});
    TreeNode* root = createTree(vec, 0);
    printTreeInorder(root);
    std::cout<<std::endl;
    std::cout<<s.maxPathSum(root)<<std::endl;
}
void test5(){
    Solution s;
    vector<int> vec({2,-1});
    TreeNode* root = createTree(vec, 0);
    printTreeInorder(root);
    std::cout<<std::endl;
    std::cout<<s.maxPathSum(root)<<std::endl;
}


#endif /* binaryTreeMaxPathSum_hpp */
