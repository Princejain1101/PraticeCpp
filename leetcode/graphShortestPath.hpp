//
//  graphShortestPath.hpp
//  leetcode
//
//  Created by Prince Jain on 7/6/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef graphShortestPath_h
#define graphShortestPath_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include "graphW.h"

using namespace std;
struct comparator{
    bool operator()(const pair<int,int> &a, const pair<int,int>& b) const {
        return a.first < b.first;
    }
};
class minHeap{
public:
    vector<pair<int,int>> distances;
    map<int,int> positions;
//    map<int,int> distMap;
//    int minI;
//    int minV;
//    minHeap():minI(-1),minV(INT_MAX){}
    int parent(int i){ return (i-1)/2;}
    int left(int i){ return 2*i + 1;}
    int right(int i){ return 2*i +2;}
    
    void insertNode(int u, int d){
        int i = (int)distances.size();
        distances.push_back({u,d});
        positions[u] = i;
        int p = parent(i);
        while(i>0 && distances[p].second > distances[i].second){
            positions[u] = p;
            positions[distances[p].first] = i;
            swap(distances[i], distances[p]);
            i = parent(i);
            p = parent(i);
        }
    }
    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < distances.size() && distances[i].second > distances[l].second){
            smallest = l;
        }
        if(r < distances.size() && distances[i].second > distances[r].second){
            smallest = r;
        }
        if(i != smallest){
            positions[distances[i].first] = smallest;
            positions[distances[smallest].first] = i;
            swap(distances[i], distances[smallest]);
            heapify(smallest);
        }
    }
    void updateNode(int u, int d){
        if(positions.find(u) == positions.end()) return;
        int i = positions.at(u);
        if(distances[i].second > d){
            distances[i].second = d;
            int p = parent(i);
            while(i>0 && distances[p].second > distances[i].second){
                positions[u] = p;
                positions[distances[p].first] = i;
                swap(distances[i], distances[p]);
                i = parent(i);
                p = parent(i);
            }
        }
    }
    pair<int,int> getMin(){
        return distances[0];
    }
    pair<int,int> extractMin(){
        auto ret = distances[0];
        int u = ret.first;
        auto s = distances[distances.size()-1];
        positions.erase(u);
        positions[s.first] = 0;
        distances[0] = distances[distances.size()-1];
        distances.pop_back();
        heapify(0);
        return ret;
    }
    int getSize(){
        return (int)distances.size();
    }
};
class Solution {
public:
    // shortest path from Source to all vertices
    // mainly used for weighted graph
    // and positive weights only.
    // can be used for directed graph as well.
    // for negative weights use, bellman-ford algorithm.
    vector<pair<int,int>> DijkstraShortestPath(GraphW& g, int u) {
        vector<pair<int,int>> resultSet;
        vector<int> distances(g.V, INT_MAX);
        distances[u]=0;
//        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> minHeap;
        minHeap mh;
        for(int i=0; i<g.V; i++){
            mh.insertNode(i,distances[i]);
        }
        while(resultSet.size()<g.V){
            int u = mh.getMin().first;
            int dist = mh.getMin().second;
            resultSet.push_back({u,dist});
            mh.extractMin();
            for(auto&dv: g.edges[u]){
                int v = dv.first;
                int w = dv.second;
//                cout<<"u: "<<u<<" v: "<<v<<", w: "<<w<<endl;
                distances[v] = min(distances[v], dist + w);
//                cout<<"set: v: "<<v<<" distance: "<<distances[v]<<endl;
                mh.updateNode(v, distances[v]);
            }
            
        }
        return resultSet;
    }
    
    vector<int> DijkstraShortestPathMatrix(vector<vector<int>>& g, int u){
        int V = (int)g.size();
        //vector<int> result(V,INT_MAX);
        for(int k=0; k<V; k++){
            for(int j=0; j<V; j++){
                if(g[u][k] == INT_MAX || g[k][j]==INT_MAX)
                    continue;
//                if(g[u][j]==0){
//                    if(j==4) cout<<"k: "<<k<<" "<<g[u][k] + g[k][j]<<" "<<g[u][j]<<endl;
//                    g[u][j] = g[u][k] + g[k][j];
//                }else{
                    if(j==4) cout<<"k: "<<k<<" "<<g[u][k] + g[k][j]<<" "<<g[u][j]<<endl;
                    g[u][j] = min(g[u][k] + g[k][j], g[u][j]);
//                }
            }
        }
        return g[u];
    }
};
void test1(){
    Solution s;
    int V=9;
    GraphW graph(V);
    graph.addEdge( 0, 1, false, 4);
    graph.addEdge( 0, 7, false, 8);
    graph.addEdge( 1, 2, false, 8);
    graph.addEdge( 1, 7, false, 11);
    graph.addEdge( 2, 3, false, 7);
    graph.addEdge( 2, 8, false, 2);
    graph.addEdge( 2, 5, false, 4);
    graph.addEdge( 3, 4, false, 9);
    graph.addEdge( 3, 5, false, 14);
    graph.addEdge( 4, 5, false, 10);
    graph.addEdge( 5, 6, false, 2);
    graph.addEdge( 6, 7, false, 1);
    graph.addEdge( 6, 8, false, 6);
    graph.addEdge( 7, 8, false, 7);
    vector<pair<int,int>> shortestDistances = s.DijkstraShortestPath(graph, 0);
    sort(shortestDistances.begin(), shortestDistances.end(), comparator());
    for(auto& d:shortestDistances) cout<<d.first<<" "<<d.second<<endl;
    
    cout<<"matrix graph method- floyd marshall"<<endl;
    vector<vector<int>> graphM = {  {0, 4, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 8, INT_MAX},
                                    {4, 0, 8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 11, INT_MAX},
                                    {INT_MAX, 8, 0, 7, INT_MAX, 4, INT_MAX, INT_MAX, 2},
                                    {INT_MAX, INT_MAX, 7, 0, 9, 14, INT_MAX, INT_MAX, INT_MAX},
                                    {INT_MAX, INT_MAX, INT_MAX, 9, 0, 10, INT_MAX, INT_MAX, INT_MAX},
                                    {INT_MAX, INT_MAX, 4, 14, 10, 0, 2, INT_MAX, INT_MAX},
                                    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 2, 0, 1, 6},
                                    {8, 11, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1, 0, 7},
                                    {INT_MAX, INT_MAX, 2, INT_MAX, INT_MAX, INT_MAX, 6, 7, 0}
    };
    vector<int> dist = s.DijkstraShortestPathMatrix(graphM, 0);
    for(int i=0; i<V; i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

#endif /* graphShortestPath_h */
