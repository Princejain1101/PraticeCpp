//
//  countNodes.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef countNodes_hpp
#define countNodes_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        int ret=0;
        if(root==nullptr)
            return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        ret = left + right + 1;
        return ret;
    }
};

void test1(){
    Solution s;
    vector<int> nums({1,2,3,4,5,6});
    TreeNode* root = createTree(nums, 0);
//    printTreeInorder(root);
    cout<<s.countNodes(root)<<endl;
}
#endif /* countNodes_hpp */
