//
//  graph.h
//  leetcode
//
//  Created by Prince Jain on 7/4/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef graph_h
#define graph_h

#include <iostream>
#include <vector>

using namespace std;
class Graph{
public:
    int V;
    vector<vector<int>> edges;
    Graph(int vertices):V(vertices), edges(vertices){}
    bool addEdge(int u, int v, bool directed=false);
    Graph transpose();
};
bool Graph::addEdge(int u, int v, bool directed){
    if(u <0 || u >= V) return false;
    if(v <0 || v >= V) return false;
    edges[u].push_back(v);
//    cout<<"added edge: "<<u<<"->"<<v<<endl;
    if(!directed)
        edges[v].push_back(u);
    return true;
}
Graph Graph::transpose(){
    Graph g(V);
    for(int u=0; u<V; u++){
        for(auto &v: edges[u]){
            g.addEdge(v, u, true);
        }
    }
    return g;
}
#endif /* graph_h */
