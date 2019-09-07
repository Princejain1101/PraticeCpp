//
//  graphW.h
//  leetcode
//
//  Created by Prince Jain on 7/6/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef graphW_h
#define graphW_h
#include <iostream>
#include <vector>

using namespace std;
class GraphW{
public:
    int V;
    vector<map<int,int>> edges;
    GraphW(int vertices):V(vertices), edges(vertices){}
    bool addEdge(int u, int v, bool directed=false, int w=1);
    GraphW transpose();
};
bool GraphW::addEdge(int u, int v, bool directed, int w){
    if(u <0 || u >= V) return false;
    if(v <0 || v >= V) return false;
    edges[u].insert({v,w});
    //    cout<<"added edge: "<<u<<"->"<<v<<endl;
    if(!directed)
        edges[v].insert({u,w});
    return true;
}
GraphW GraphW::transpose(){
    GraphW g(V);
    for(int u=0; u<V; u++){
        for(auto &v: edges[u]){
            g.addEdge(v.first, u, true,v.second);
        }
    }
    return g;
}

#endif /* graphW_h */
