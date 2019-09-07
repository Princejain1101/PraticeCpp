//
//  numberofBSTs.h
//  leetcode
//
//  Created by Prince Jain on 7/11/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef numberofBSTs_h
#define numberofBSTs_h

#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"

using namespace std;
class Solution {
    int numberOfBSTUtil(TreeNode* root, int& count, bool& bst){
        
        // leaf node
//        if(root->left == nullptr && root->right == nullptr){
//            count++;
//            return root->val;
//        }
        bool lbst=true;
        int lval = INT_MIN;
        if(root->left != nullptr){
            lval = numberOfBSTUtil(root->left, count, lbst);
        }
        bool rbst=true;
        int rval = INT_MAX;
        if(root->right != nullptr){
            rval = numberOfBSTUtil(root->right, count, rbst);
        }
        if(root->val > lval && root->val < rval && lbst && rbst){
            bst = true;
            count++;
        }else{
            bst = false;
        }
        return root->val;
    }
public:
    int numberOfBST(TreeNode* root) {
        int count=0;
        if(root==nullptr) return 0;
        bool bst;
        numberOfBSTUtil(root, count, bst);
        return count;
    }
};
void test1(){
    Solution s;
    struct TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(9);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(7);
    cout<<s.numberOfBST(root)<<endl;
}

#endif /* numberofBSTs_h */
