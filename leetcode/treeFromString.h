//
//  treeFromString.h
//  leetcode
//
//  Created by Prince Jain on 7/26/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef treeFromString_h
#define treeFromString_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    TreeNode* str2treeUtil(string& s) {
        cout<<"s: "<<s<<endl;
        if(s=="") return nullptr;
        auto si = s.find('(');
        if(si == string::npos){
            cout<<"leaf"<<endl;
            int val = stoi(s);
            TreeNode* root = new TreeNode(val);
            return root;
        }
        int val = stoi(s.substr(0,si));
        cout<<val<<endl;
        TreeNode* root = new TreeNode(val);
        int parenthesis=1;
        int i=(int)si+1;
        for(; i<s.size(); i++){
            if(s[i]=='('){
                parenthesis++;
            }else if(s[i]==')'){
                parenthesis--;
            }
            if(parenthesis==0) break;
        }
        cout<<"i: "<<i<<endl;

        string sl = s.substr(si+1,i-si-1);
        root->left = str2treeUtil(sl);
        if(i+2>=s.size()) return root;
        string sr = s.substr(i+2,s.size()-1 - (i+2));
        root->right = str2treeUtil(sr);
        return root;
    }
};
void test1(){
    Solution s;
    string str = "-4(-2)(-6)";
    auto root = s.str2treeUtil(str);
    printTreePreorder(root);
}

#endif /* treeFromString_h */
