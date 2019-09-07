//
//  verticalTraversal.h
//  leetcode
//
//  Created by Prince Jain on 7/14/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef verticalTraversal_h
#define verticalTraversal_h

#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include "tree.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> resultmap;
        if(root==nullptr) return vector<vector<int>>();
        stack<pair<TreeNode*,int>> st;
        st.push({root,0});
        while(!st.empty()){
            auto a = st.top();
            st.pop();
            TreeNode* node = a.first;
            int level = a.second;
            resultmap[level].push_back(node->val);
            if(node->left) st.push({node->left, level-1});
            if(node->right) st.push({node->right, level+1});
        }
        vector<vector<int>> result;
        for(auto &m: resultmap){
            result.push_back(m.second);
        }
        return result;
    }
};
void test1(){
    Solution s;
    vector<int> vec({3,9,20,null,null,15,7});
    TreeNode* root = createTree(vec, 0);
    vector<vector<int>> result = s.verticalTraversal(root);
    for(auto &v: result){
        for(auto &i: v){
            cout<<i<<",";
        }
        cout<<endl;
    }
}
#endif /* verticalTraversal_h */
