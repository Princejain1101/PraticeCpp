//
//  numIslands.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef numIslands_hpp
#define numIslands_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
    bool _inBoundary(vector<vector<char>> &grid, int i, int j){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size())
            return true;
        return false;
    }
    void _traceIsland(vector<vector<char>> &grid, int i, int j){
//        cout<<"i: "<<i<<", j: "<<j<<endl;
        if(!_inBoundary(grid, i, j))
            return;
        if(grid[i][j] == '1'){
//            cout<<"set 2"<<endl;
            grid[i][j] = '2';
            _traceIsland(grid, i+1, j);
            _traceIsland(grid, i-1, j);
            _traceIsland(grid, i, j+1);
            _traceIsland(grid, i, j-1);
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    islands++;
                    _traceIsland(grid, i, j);
                }
            }
        }
        return islands;
    }
};
void test1(){
    Solution s;
    vector<vector<char>> grid({ {'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}});
    cout<<s.numIslands(grid)<<endl;
}
#endif /* numIslands_hpp */
