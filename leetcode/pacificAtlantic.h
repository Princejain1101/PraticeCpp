//
//  pacificAtlantic.h
//  leetcode
//
//  Created by Prince Jain on 7/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef pacificAtlantic_h
#define pacificAtlantic_h
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    void _pacificAtlanticUtil(vector<vector<int>>& matrix, int i, int j,
                              bool& P, bool& A, set<vector<int>>& result, vector<vector<int>>& visited,
                              vector<vector<bool>> &rec,
                              int val){
        cout<<"i: "<<i<<", j: "<<j<<endl;
        if(i<0 || j<0){
            P = true;
            return;
        }
        if(i>=(int)matrix.size() || j >= (int)matrix[0].size()){
            A = true;
            return;
        }
        if(matrix[i][j]>val) {
            return;
        }
        if(rec[i][j]==true) return;
        rec[i][j] = true;
        bool Pb = false;
        bool Ab = false;
        _pacificAtlanticUtil(matrix, i-1, j, Pb, Ab, result, visited, rec, matrix[i][j]);
        _pacificAtlanticUtil(matrix, i+1, j, Pb, Ab, result, visited, rec, matrix[i][j]);
        _pacificAtlanticUtil(matrix, i, j-1, Pb, Ab, result, visited, rec, matrix[i][j]);
        _pacificAtlanticUtil(matrix, i, j+1, Pb, Ab, result, visited, rec, matrix[i][j]);
        P = P | Pb;
        A = A | Ab;
        
        if(Pb && Ab){
            result.insert(vector<int>({i,j}));
        }
        if(Pb && Ab){
            visited[i][j]=3;
        }else if(Pb){
            visited[i][j]=1;
        }else if(Ab){
            visited[i][j]=2;
        }else visited[i][j]=0;

        rec[i][j] = false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        set<vector<int>> result;
        int m = (int)matrix.size();
        if(m==0) return vector<vector<int>>(result.begin(),result.end());
        int n = (int)matrix[0].size();
        vector<vector<bool>> rec(m,vector<bool>(n,false));
        vector<vector<int>> visited(m,vector<int>(n,-1));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j]!=3){
                    bool P=false;
                    bool A=false;
                    _pacificAtlanticUtil(matrix, i, j, P, A, result, visited, rec, INT_MAX);
                }
            }
        }
        vector<vector<int>> resultvec(result.begin(),result.end());
        return resultvec;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> matrix = {  {1,2,2,3,5},
                                    {3,2,3,4,4},
                                    {2,4,5,3,1},
                                    {6,7,1,4,5},
                                    {5,1,1,2,4} };
    vector<vector<int>> result = s.pacificAtlantic(matrix);
    for(auto &r: result){
        for(auto& a: r){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}
void test2(){
    Solution s;
    vector<vector<int>> matrix={{10,10,10},
                                {10,1,10},
                                {10,10,10}};
    vector<vector<int>> result = s.pacificAtlantic(matrix);
    for(auto &r: result){
        for(auto& a: r){
            cout<<a<<" ";
        }
        cout<<endl;
    }
}

#endif /* pacificAtlantic_h */
