//
//  findWords.hpp
//  leetcode
//
//  Created by Prince Jain on 6/17/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef findWords_hpp
#define findWords_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution {
    bool _inBoundary(vector<vector<char>>& board, int i, int j){
        cout<<"check i: "<<i<<", j: "<<j<<endl;
        if(i<0 || j <0){
            cout<<"returning false"<<endl;
            return false;
        }
        if(i>= board.size() || j >=board[0].size()){
            cout<<"returning false"<<endl;
            return false;
        }
        cout<<"returning true"<<endl;
        return true;
    }
    void _addToResult(set<int> &ret, set<int>& newret, set<int> & indices){
        for(auto &i:newret){
            ret.insert(i);
            indices.erase(indices.find(i));
        }
    }
    set<int> _findWordsUtil(vector<vector<char>>& board, vector<string> &words, set<int> indices, int step, int i, int j, vector<vector<bool>> & done){
        set<int> ret;

        if(!_inBoundary(board, i, j)){
            cout<<"boundary error"<<endl;
            return ret;
        }
        cout<<"in boundary"<<endl;
        if(done[i][j]==true){
            cout<<"done i: "<<i<<", j: "<<j<<endl;
            return ret;
        }
        cout<<"not done"<<endl;
        if(indices.size()==0){
            cout<<"empty indices"<<endl;
            return ret;
        }
        cout<<"list not empty"<<endl;
        done[i][j]=true;
        set<int> newIndices=indices;
        char check = board[i][j];
        cout<<"check: "<<check<<", step:"<<step<<endl;
        for(auto it=indices.begin(); it!=indices.end(); it++){
            int i=*it;
            cout<<words[i]<<endl;
            if(words[i][step] != check){
                newIndices.erase(newIndices.find(i));
                cout<<"removing: "<<words[i]<<endl;
                continue;
            }
            if(words[i].size()-1 == step){
                ret.insert(i);
//                ret.push_back(words[i]);
                newIndices.erase(newIndices.find(i));
                cout<<"removing and returning: "<<words[i]<<endl;
                continue;
            }
        }
        for(auto &i:newIndices){
            cout<<"new word list: "<<words[i]<<endl;
        }
        cout<<"newIndices size: "<<newIndices.size()<<endl;
        set<int> retleft = _findWordsUtil(board, words, newIndices, step+1, i-1, j, done);
        _addToResult(ret, retleft,newIndices);
        set<int> retright = _findWordsUtil(board, words, newIndices, step+1, i+1, j, done);
        _addToResult(ret, retright,newIndices);
        set<int> rettop = _findWordsUtil(board, words, newIndices, step+1, i, j-1, done);
        _addToResult(ret, rettop,newIndices);
        set<int> retbottom = _findWordsUtil(board, words, newIndices, step+1, i, j+1, done);
        _addToResult(ret, retbottom,newIndices);
        done[i][j] = false;
        
        return ret;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<int> indices;
        for(int i=0; i<words.size(); i++){
            indices.insert(i);
        }
//        std::iota(indices.begin(), indices.end(),0);
        set<int> ret;
        for(int i=0; i<board.size(); i++){

            for(int j=0; j<board[0].size(); j++){
                vector<vector<bool>> done;
                for(int k=0; k<board.size(); k++){
                    vector<bool> row(board[0].size(),false);
                    done.push_back(row);
                }

                cout<<"char: "<<board[i][j]<<endl;
                set<int> tempret = _findWordsUtil(board, words, indices, 0, i, j, done);
                _addToResult(ret, tempret,indices);
            }
        }
        vector<string> result;
        for(auto &i:ret){
            result.push_back(words[i]);
        }
        return result;
    }
};
void test1(){
    Solution s;
    vector<vector<char>> board({
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    });
    vector<string> words ({"oath","pea","eat","rain"});
    vector<string> res = s.findWords(board, words);
    for(auto &s:res){
        cout<<s<<" ";
    }
    cout<<endl;
}
void test2(){
    Solution s;
    vector<vector<char>> board({ {'b'},{'a'},{'b'},{'b'},{'a'}
    });
    vector<string> words ({"baa","abba","baab","aba"});
    vector<string> res = s.findWords(board, words);
    for(auto &s:res){
        cout<<s<<" ";
    }
    cout<<endl;
}
#endif /* findWords_hpp */
