//
//  diameterOfBinaryTree.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef diameterOfBinaryTree_hpp
#define diameterOfBinaryTree_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"


using namespace std;
class Solution {
    int _diameterOfBTUtil(TreeNode* root, int &path){
        if(root == nullptr){
            path=0;
            return 0;
        }
        int pathLeft;
        int leftMax = _diameterOfBTUtil(root->left, pathLeft);
        int pathRight;
        int rightMax = _diameterOfBTUtil(root->right, pathRight);
        path = max(pathLeft,pathRight)+1;
        int totalmax=0;
        totalmax = max(leftMax,rightMax);
        totalmax = max(totalmax,pathLeft+pathRight+1);
        return totalmax;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int path=0;
        return _diameterOfBTUtil(root, path)-1;
    }
};
void test1(){
    Solution s;
    vector<int> treevec({1,2,3,4,5});
    TreeNode* root = createTree(treevec, 0);
//    printTreeInorder(root);
    cout<<s.diameterOfBinaryTree(root)<<endl;
}
#endif /* diameterOfBinaryTree_hpp */
