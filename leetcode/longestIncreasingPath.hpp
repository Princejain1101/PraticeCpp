//
//  longestIncreasingPath.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef longestIncreasingPath_hpp
#define longestIncreasingPath_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    bool _inBoundary(vector<vector<int>> &grid,int i, int j){
        if(i<0) return false;
        if(j<0) return false;
        if(i>=grid.size()) return false;
        if(j>=grid[0].size()) return false;
        return true;
    }
    int _longestPathUtil(vector<vector<int>>& matrix, vector<vector<int>>& path, int i, int j, int val){
        if(!_inBoundary(matrix, i, j))
            return 0;
        if(matrix[i][j] <= val)
            return 0;
        if(path[i][j] != -1){
            return path[i][j];
        }
        int left = _longestPathUtil(matrix, path, i-1, j, matrix[i][j]);
        int right = _longestPathUtil(matrix, path, i+1, j, matrix[i][j]);
        int top = _longestPathUtil(matrix, path, i, j+1, matrix[i][j]);
        int bottom = _longestPathUtil(matrix, path, i, j-1, matrix[i][j]);

        int length = max(max(left,right),max(top,bottom)) +1;
        path[i][j] = length;
        return length;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> path(matrix.size());
        for(auto &i:path){
            vector<int> row(matrix[0].size(),-1);
            i = row;
        }
        int max=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(path[i][j]==-1){
                    int length = _longestPathUtil(matrix, path, i, j, INT_MIN);
                    max = max > length ? max : length;
                }
            }
        }
        return max;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> matrix({{9,9,4},
                                {6,6,8},
                                {2,1,1}});
    cout<<s.longestIncreasingPath(matrix)<<endl;
}
void test2(){
    Solution s;
    vector<vector<int>> matrix({{3,4,5},
        {3,2,6},
        {2,2,1}});
    cout<<s.longestIncreasingPath(matrix)<<endl;
}

#endif /* longestIncreasingPath_hpp */
