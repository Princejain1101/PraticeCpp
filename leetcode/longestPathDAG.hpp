//
//  longestPathDAG.hpp
//  leetcode
//
//  Created by Prince Jain on 6/28/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef longestPathDAG_hpp
#define longestPathDAG_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {}
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
class Solution {
    int _dfsUtil(vector<int> adj[], int curr, vector<int> &visited){
        if(visited[curr] == -1) return 0;
        if(visited[curr] !=0) return visited[curr];
        visited[curr] = -1;
        int maxpath=0;
        for(int i=0; i<adj[curr].size(); i++){
            maxpath = max(maxpath, _dfsUtil(adj, adj[curr][i], visited));
        }
        visited[curr] = maxpath+1;
        return maxpath+1;
    }
    int _dfsUtilTarget(vector<int> adj[], int curr, vector<int> &visited, int target){
        if(visited[curr] == -1) return 0;
        if(visited[curr] !=0) return visited[curr];
        if(curr == target) return 1;
        visited[curr] = -1;
        int maxpath=0;
//        cout<<"curr: "<<curr<<endl;
        for(int i=0; i<adj[curr].size(); i++){
            maxpath = max(maxpath, _dfsUtilTarget(adj, adj[curr][i], visited,target));
//            cout<<"maxpath: "<<maxpath<<endl;
        }

        if(maxpath > 0) maxpath = maxpath+1;
        visited[curr] = maxpath;
        return maxpath;
    }
    int _dfsUtilShortTarget(vector<int> adj[], int curr, vector<int> &visited, int target){
        if(visited[curr] == -1) return INT_MAX;
        if(visited[curr] !=0) return visited[curr];
        if(curr == target) return 0;
        visited[curr] = -1;
        int shortpath=INT_MAX;
        //        cout<<"curr: "<<curr<<endl;
        for(int i=0; i<adj[curr].size(); i++){
            shortpath = min(shortpath, _dfsUtilShortTarget(adj, adj[curr][i], visited,target));
            //            cout<<"maxpath: "<<maxpath<<endl;
        }
        
        if(shortpath != INT_MAX) shortpath = shortpath+1;
        visited[curr] = shortpath;
        return shortpath;
    }

public:
    int findLongestPath(vector<int> adj[], int n) {
        vector<int> visited(n,0);
        int maxpath=0;
        for(int i=0; i<n; i++){
            maxpath = max(maxpath, _dfsUtil(adj, i, visited));
        }
        return maxpath-1;
    }
    int findLongestPathTarget(vector<int> adj[], int n, int target) {
        vector<int> visited(n,0);
        int maxpath=0;
        for(int i=0; i<n; i++){
            maxpath = max(maxpath, _dfsUtilTarget(adj, i, visited, target));
        }
        return maxpath-1;
    }
    int findShortestPathTarget(vector<int> adj[], int n, int target) {
        vector<int> visited(n,0);
        int shortpath=INT_MAX;
        for(int i=0; i<n; i++){
            shortpath = min(shortpath, _dfsUtilShortTarget(adj, i, visited, target));
        }
        if(shortpath==INT_MAX) return -1;
        return shortpath;
    }
    int findShortestPathTargetFromSource(vector<int> adj[], int n, int target, int source) {
        vector<int> visited(n,0);
        int shortpath=INT_MAX;
        shortpath = min(shortpath, _dfsUtilShortTarget(adj, source, visited, target));
        if(shortpath==INT_MAX) return -1;
        return shortpath;
    }
};
void test1(){
    cout<<"test1"<<endl;
    Solution s;
    int n = 4;
    vector<int> adj[n];
    
    // Example-1
    
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 0);
    cout<<s.findLongestPath(adj, n)<<endl;
    cout<<s.findLongestPathTarget(adj, n, 2)<<endl;
}
void test2(){
    cout<<"test2"<<endl;
    Solution s;
    int n = 5;
    vector<int> adj[n];
    
    // Example-1
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 4, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    cout<<s.findLongestPath(adj, n)<<endl;
    cout<<s.findLongestPathTarget(adj, n, 1)<<endl;
    cout<<s.findShortestPathTarget(adj, n, 1)<<endl;
    cout<<s.findShortestPathTargetFromSource(adj, n, 1,3)<<endl;
}

#endif /* longestPathDAG_hpp */
