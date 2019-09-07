//
//  splitBST.h
//  leetcode
//
//  Created by Prince Jain on 7/18/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef splitBST_h
#define splitBST_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    TreeNode* splitBSTUtil(TreeNode* root, int v, TreeNode* &res){
        if(root==nullptr) {
            res = nullptr;
            return nullptr;
        };
        if(v == root->val){
            res = root->right;
            root->right = nullptr;
            return root;
        }
        if(v < root->val){
            root->left = splitBSTUtil(root->left, v, res);
            TreeNode* ret = root->left;
            root->left = res;
            res = root;
            return ret;
        }else{
            root->right = splitBSTUtil(root->right, v, res);
            return root;
        }
    }
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode* > result;
        TreeNode* bst2;
        TreeNode* bst1 = splitBSTUtil(root, V, bst2);
        result.push_back(bst1);
        result.push_back(bst2);
        return result;
    }
};
void test1(){
    Solution s;
    vector<int> bstvec({4,2,6,1,3,5,7});
    TreeNode* bst = createTree(bstvec, 0);
    cout<<"input: ";
    printTreePreorder(bst); cout<<endl;
    printTreeInorder(bst);
    vector<TreeNode*> result = s.splitBST(bst, 2);
    cout<<endl;
    TreeNode* bst1 = result[0];
    TreeNode* bst2 = result[1];
    
    cout<<"bst1: "; printTreePreorder(bst1); cout<<endl;
    cout<<"bst2: "; printTreePreorder(bst2); cout<<endl;
}

#endif /* splitBST_h */
