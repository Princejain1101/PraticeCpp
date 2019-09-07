//
//  BalancedBSTfromLinkList.h
//  leetcode
//
//  Created by Prince Jain on 7/11/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef BalancedBSTfromLinkList_h
#define BalancedBSTfromLinkList_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"
#include "list.h"

using namespace std;
class Solution {
    TreeNode* BalancedBSTUtil(ListNode* &node, int n){
        if(n==0) return nullptr;
        int l = n/2;
        TreeNode* left = BalancedBSTUtil(node, l);
        TreeNode* root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        TreeNode* right = BalancedBSTUtil(node, n-l-1);
        root->right = right;
        return root;
    }
public:
    TreeNode* BalancedBSTFromLinkList(ListNode* head) {
        int n=0;
        ListNode* node = head;
        while(node != nullptr){
            node = node->next;
            n++;
        }
        node = head;
        return BalancedBSTUtil(node, n);
    }
};
void test1(){
    Solution s;
    vector<int> vec({1,2,3,4,5,6,7});
    ListNode* head = createList(vec);
    TreeNode* bst = s.BalancedBSTFromLinkList(head);
    printTreeInorder(bst);
}

#endif /* BalancedBSTfromLinkList_h */
