//
//  distanceK.h
//  leetcode
//
//  Created by Prince Jain on 7/25/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef distanceK_h
#define distanceK_h

#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    TreeNode* findval(TreeNode* root, int val){
        if(root==nullptr) return nullptr;
        if(root->val == val) return root;
        auto left = findval(root->left, val);
        if(left) return left;
        auto right = findval(root->right, val);
        return right;
    }
    int dfs(TreeNode* root, TreeNode* target, int K, vector<int>& result, bool& found){
        if(root==nullptr) return 0 ;
        if(found == true){
            if(K==0){
                result.push_back(root->val);
            }else{
                dfs(root->left, target, K-1, result, found);
                dfs(root->right, target, K-1, result, found);
            }
            return 0;
        }
        if(root == target){
            found = true;
            if(K==0){
                result.push_back(root->val);
            }else{
                dfs(root->left, target, K-1, result, found);
                dfs(root->right, target, K-1, result, found);
            }
            return 1;
        }
        int leftdistance = dfs(root->left, target, K, result, found);
        if(found){
            if(leftdistance==K){
                result.push_back(root->val);
            }else if(leftdistance < K){
                dfs(root->right, target, K-leftdistance-1, result, found);
            }
            return leftdistance + 1;
        }
        int rightdistance = dfs(root->right, target, K, result, found);
        if(rightdistance==K){
            result.push_back(root->val);
        }else if(rightdistance < K){
            dfs(root->left, target, K-rightdistance-1, result, found);
        }
        return rightdistance + 1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        bool found=false;
        dfs(root, target, K, result, found);
        return result;
    }
};
void test1(){
    Solution s;
    int K = 2;
    vector<int> vec({3,5,1,6,2,0,8,null,null,7,4});
    TreeNode* root = createTree(vec, 0);
    TreeNode* target = s.findval(root, 5);
    
    vector<int> result = s.distanceK(root, target, K);
    for(auto &i: result) cout<<i<<", ";
    cout<<endl;
}
void test2(){
    Solution s;
    int K = 1;
    vector<int> vec({0,1,null,3,2});
    TreeNode* root = createTree(vec, 0);
    TreeNode* target = s.findval(root, 2);
    
    vector<int> result = s.distanceK(root, target, K);
    for(auto &i: result) cout<<i<<", ";
    cout<<endl;
}
#endif /* distanceK_h */
