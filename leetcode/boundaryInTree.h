//
//  boundaryInTree.h
//  leetcode
//
//  Created by Prince Jain on 7/25/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef boundaryInTree_h
#define boundaryInTree_h

#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    bool ifLeaf(TreeNode* root){
        if(root==nullptr) return false;
        if(root->left) return false;
        if(root->right) return false;
        return true;
    }
    void addLeaf(vector<int>& vec, TreeNode* root){
        if(root== nullptr) return;
        if(ifLeaf(root)){
            vec.push_back(root->val);
        }
        addLeaf(vec, root->left);
        addLeaf(vec, root->right);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> boundary;
        if(root==nullptr) return boundary;
        boundary.push_back(root->val);
        // adding left boundary
        TreeNode* left = root->left;
        while(left){
            if(!ifLeaf(left)){
                boundary.push_back(left->val);
            }
            if(left->left){
                left = left->left;
            }else{
                left = left->right;
            }
        }
        addLeaf(boundary, root->left);
        addLeaf(boundary, root->right);
        
        TreeNode* right = root->right;
        stack<int> rightst;
        while(right){
            if(!ifLeaf(right)){
                rightst.push(right->val);
            }
            if(right->right){
                right = right->right;
            }else{
                right = right->left;
            }
        }
        while(!rightst.empty()){
            boundary.push_back(rightst.top());
            rightst.pop();
        }
        return boundary;
    }
    // using preorder
    void boundaryPreorderUtil(TreeNode* root, vector<int>& leftb, vector<int>& rightb, vector<int>& leafb, int flag){
        if(root==nullptr) return;
        if(ifLeaf(root)){
            leafb.push_back(root->val);
        } else if(flag == 1 || flag ==0) {// left boundary or root
            leftb.push_back(root->val);
        } else if(flag == 2) {// right boundary
            rightb.insert(rightb.begin(), root->val);
        }
        int flagleft=3;
        int flagright=3;
        if(flag==1){
            flagleft = 1;
            if(root->left == nullptr){
                flagright = 1;
            }
        }else if(flag == 2){
            flagright = 2;
            if(root->right == nullptr){
                flagleft = 2;
            }
        }else{
            flagleft = 1;
            flagright = 2;
        }
        boundaryPreorderUtil(root->left, leftb, rightb, leafb, flagleft);
        boundaryPreorderUtil(root->right, leftb, rightb, leafb, flagright);
    }
    vector<int> boundaryOfBinaryTree2(TreeNode* root) {
        vector<int> leftb;
        vector<int> leafb;
        vector<int> rightb;
        if(root==nullptr) return leafb;
        boundaryPreorderUtil(root, leftb, rightb, leafb, 0);
        for(auto &i: leftb) {
            cout<<i<<",";
        }
        cout<<endl;
        for(auto &i: leafb) {
            cout<<i<<",";
            leftb.push_back(i);
        }
        cout<<endl;
        for(auto &i: rightb) {
            cout<<i<<",";
            leftb.push_back(i);
        }
        cout<<endl;
        return leftb;
    }
};
void test1(){
    Solution s;
    vector<int> vec({1,2,3,4,5,6,null,null,null,7,8,9,10});
    TreeNode* root = createTree(vec, 0);
    vector<int> result = s.boundaryOfBinaryTree2(root);
    for(auto &i: result) cout<<i<<", ";
    cout<<endl;
}
void test2(){
    Solution s;
    vector<int> vec({-64,12,18,-4,-53,null,76,null,-51,null,null,-93,3,null,-31,47,null,3,53,-81,33,4,null,-51,-44,-60,11,null,null,null,null,78,null,-35,-64,26,-81,-31,27,60,74,null,null,8,-38,47,12,-24,null,-59,-49,-11,-51,67,null,null,null,null,null,null,null,-67,null,-37,-19,10,-55,72,null,null,null,-70,17,-4,null,null,null,null,null,null,null,3,80,44,-88,-91,null,48,-90,-30,null,null,90,-34,37,null,null,73,-38,-31,-85,-31,-96,null,null,-18,67,34,72,null,-17,-77,null,56,-65,-88,-53,null,null,null,-33,86,null,81,-42,null,null,98,-40,70,-26,24,null,null,null,null,92,72,-27,null,null,null,null,null,null,-67,null,null,null,null,null,null,null,-54,-66,-36,null,-72,null,null,43,null,null,null,-92,-1,-98,null,null,null,null,null,null,null,39,-84,null,null,null,null,null,null,null,null,null,null,null,null,null,-93,null,null,null,98});
    TreeNode* root = createTree(vec, 0);
    vector<int> result = s.boundaryOfBinaryTree2(root);
    for(auto &i: result) cout<<i<<", ";
    cout<<endl;
}
#endif /* boundaryInTree_h */
