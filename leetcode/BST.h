//
//  BST.h
//  leetcode
//
//  Created by Prince Jain on 7/10/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <vector>
#include <string>
#include <map>
#include <set>
#include "tree.hpp"

using namespace std;
class Solution {
public:
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        cout<<root->val<<", ";
        inorder(root->right);
    }
    void preorder(TreeNode* root){
        if(root==nullptr) return;
        cout<<root->val<<", ";
        preorder(root->left);
        preorder(root->right);
    }
    TreeNode* insert(TreeNode* root, int key){
        if(root==nullptr) {
            TreeNode* newnode = new TreeNode(key);
            return newnode;
        }
        if(key < root->val){
            root->left = insert(root->left, key);
        }else{
            root->right = insert(root->right, key);
        }
        return root;
    }
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        return root->height;
    }
    
    int isBalanced(TreeNode* root){
        if(root == nullptr) return 0;
        if(root->left==nullptr) return -(1+height(root->right));
        if(root->right==nullptr) return height(root->left)+1;
        return height(root->left) - height(root->right);
    }
    TreeNode* rotateRight(TreeNode* y){
        TreeNode* x = y->left;
        
        y->left = x->right;
        x->right = y;
        
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        
        return x;
    }
    
    TreeNode* rotateLeft(TreeNode* y){
        TreeNode* x = y->right;
        
        y->right = x->left;
        x->left = y;
        
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        
        return x;
    }
    TreeNode* insertBalanced(TreeNode* root, int key){
        if(root == nullptr){
            TreeNode* root = new TreeNode(key);
            return root;
        }
        
        if(key < root->val){
            root->left = insertBalanced(root->left, key);
        }else if( key > root->val){
            root->right = insertBalanced(root->right, key);
        }else{
            return root;
        }
        
        root->height = max (height(root->left), height(root->right)) + 1;
        int balance = isBalanced(root);
//        cout<<"root: "<<root->val<<", height: "<<root->height<<", balance: "<<balance<<endl;
        // rotation cases
        // left, left
        if(balance > 1 && key < root->left->val){
            return rotateRight(root);
        }
        // left, right
        if(balance > 1 && key > root->left->val){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        // right, right
        if(balance < -1 && key > root->right->val){
            return rotateLeft(root);
        }
        // right, left
        if(balance < -1 && key < root->right->val){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        return root;
    }
    TreeNode* deleteBalanced(TreeNode* root, int key){
        if(root==nullptr) return nullptr;
        if(key < root->val){
            root->left = deleteBalanced(root->left, key);
        }else if(key > root->val){
            root->right = deleteBalanced(root->right, key);
        }else{
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                root = nullptr;
            }else if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                root = temp;
            }else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                root = temp;
            }else{
                TreeNode* parent = root->right;
                TreeNode* curr = parent;
                while(curr->left != nullptr){
                    parent = curr;
                    curr = curr->left;
                }
                root->val = curr->val;
                parent->left = curr->right;
                delete curr;
            }
        }
        
        if(root==nullptr) return root;
        root->height = max(height(root->left), height(root->right)) + 1;
        
        int balance = isBalanced(root);
        
        // rotation cases
        // left, left
        if(balance > 1 && isBalanced(root->left)>=0){
            return rotateRight(root);
        }
        // left, right
        if(balance > 1 && isBalanced(root->left)<0){
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        // right, right
        if(balance < -1 && isBalanced(root->right)<=0){
            return rotateLeft(root);
        }
        // right, left
        if(balance < -1 && isBalanced(root->right)>0){
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        return root;
        
    }
    TreeNode* _getLeftMost(TreeNode* root){
        if(root==nullptr) return nullptr;
        while(root->left != nullptr){
//            cout<<root->val<<endl;
            root = root->left;
        }
        return root;
    }
    TreeNode* _getRightMost(TreeNode* root){
        if(root==nullptr) return nullptr;
        while(root->right != nullptr){
//            cout<<root->val<<endl;
            root = root->right;
        }
        return root;
    }
    TreeNode* getInorderSucc(TreeNode* root, int key){
        TreeNode* curr = root;
        while(curr != nullptr){
            if(key == curr->val){
                break;
            }else if(key < curr->val){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        if(curr == nullptr) return nullptr;
        if(curr->right == nullptr){
            TreeNode* succ=nullptr;
            while(root != nullptr){
                if(key < root->val){
                    succ = root;
                    root = root->left;
                }else if(key > root->val){
                    root = root->right;
                }else{
                    break;
                }
            }
            return succ;
        }else{
            curr = curr->right;
            while(curr->left != nullptr){
                curr = curr->left;
            }
            return curr;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root==nullptr) return root;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }
        if(root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        else{
            // get the successor of the root
//            TreeNode* leftmost = _getLeftMost(root->right);
//            root->val = leftmost->val;
//            root->right = deleteNode(root->right, leftmost->val);
//            return root;
            TreeNode* succ = root->right;
            TreeNode* succparent = succ;
            while(succ->left != nullptr){
                succparent = succ;
                succ = succ->left;
            }
            root->val = succ->val;
            succparent->left = succ->right;
            delete succ;
            return root;
        }
    }
    void fillInorderSucc(TreeNode* root){
        static TreeNode* next=nullptr;
        if(root==nullptr) return;
        // visit right node first
        fillInorderSucc(root->right);
        root->next = next;
        next = root;
        fillInorderSucc(root->left);
    }
    void fillInorderPred(TreeNode* root){
        static TreeNode* prev=nullptr;
        if(root==nullptr) return;
        fillInorderPred(root->left);
        root->prev = prev;
        prev = root;
        fillInorderPred(root->right);
    }
};
void test1(){
    Solution s;
    TreeNode* root = nullptr;
    root = s.insert(root, 50);
    root = s.insert(root, 30);
    root = s.insert(root, 20);
    root = s.insert(root, 40);
    root = s.insert(root, 70);
    root = s.insert(root, 60);
    root = s.insert(root, 80);
    
    cout<<"inorder: ";
    s.inorder(root);
    cout<<endl;
    
    cout<<"preorder: ";
    s.preorder(root);
    cout<<endl;

    
//    cout<<"deleting 20"<<endl;
//    s.deleteNode(root, 20);
//    s.inorder(root);
//    cout<<endl;
//
//    cout<<"deleting 30"<<endl;
//    s.deleteNode(root, 30);
//    s.inorder(root);
//    cout<<endl;
//
//    cout<<"deleting 50"<<endl;
//    s.deleteNode(root, 50);
//    s.inorder(root);
//    cout<<endl;
//    cout<<"next fill: ";
//    s.fillInorderSucc(root);
//    TreeNode* leftmost = s._getLeftMost(root);
//    TreeNode* next = leftmost;
//    while(next != nullptr){
//        cout<<next->val<<", ";
//        next = next->next;
//    }
//    cout<<endl;
//
//    cout<<"prev fill: ";
//    s.fillInorderPred(root);
//    TreeNode* rightmost = s._getRightMost(root);
//    TreeNode* prev = rightmost;
//    while(prev != nullptr){
//        cout<<prev->val<<", ";
//        prev = prev->prev;
//    }
//    cout<<endl;
//
//    TreeNode* succ = s.getInorderSucc(root, 40);
//    if(succ != nullptr) cout<<succ->val<<endl;
    
    TreeNode* rootB = nullptr;
//    cout<<"inserting 20"<<endl;
    rootB = s.insertBalanced(rootB, 20);
//    cout<<"inserting 30"<<endl;
    rootB = s.insertBalanced(rootB, 30);
//    cout<<"inserting 40"<<endl;
    rootB = s.insertBalanced(rootB, 40);
//    cout<<"inserting 50"<<endl;
    rootB = s.insertBalanced(rootB, 50);
//    cout<<"inserting 60"<<endl;
    rootB = s.insertBalanced(rootB, 60);
//    cout<<"inserting 70"<<endl;
    rootB = s.insertBalanced(rootB, 70);
//    cout<<"inserting 80"<<endl;
    rootB = s.insertBalanced(rootB, 80);

    cout<<"inorder balanced: ";
    s.inorder(rootB);
    cout<<endl;

    cout<<"preorder balanced: ";
    s.preorder(rootB);
    cout<<endl;
    
//    TreeNode* leftmost = s._getLeftMost(rootB);
//    cout<<leftmost->val<<endl;
//
//    TreeNode* rightmost = s._getRightMost(rootB);
//    cout<<rightmost->val<<endl;
    rootB = s.deleteBalanced(root, 20);
    cout<<"inorder balanced: ";
    s.inorder(rootB);
    cout<<endl;

    cout<<"preorder balanced: ";
    s.preorder(rootB);
    cout<<endl;

}

#endif /* BST_h */
