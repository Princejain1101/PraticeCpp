//
//  MST.h
//  leetcode
//
//  Created by Prince Jain on 7/7/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef MST_h
#define MST_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include "graphW.h"

using namespace std;
struct Edge{
    int src;
    int dest;
    int weight;
    Edge(int s, int d, int w):src(s),dest(d),weight(w){}
    bool operator== (const Edge& e1) const {
        if(e1.src == src && e1.dest == dest && e1.weight == weight)
            return true;
        return false;
    }
};

struct comparator{
    bool operator()(const Edge& e1, const Edge& e2) const{
        return e1.weight < e2.weight;
    }
};
class Solution {
    int Find(int u, vector<pair<int,int>> &parent){
        while(parent[u].first != u){
            u = parent[u].first;
        }
        return u;
    }
    void Union(int u, int v, vector<pair<int,int>> &parent){
        if(parent[u].second < parent[v].second){
            parent[u].first = v;
            return;
        }
        if(parent[v].second < parent[u].second){
            parent[v].first = u;
            return;
        }
        parent[v].first = u;
        parent[u].second++;
    }
public:
    vector<Edge> MSTKruskalsSetDisjointSetUnionFind(GraphW& g) {
        vector<Edge> edges;
        for(int i=0; i<g.V; i++){
            for(auto &m: g.edges[i]){
                Edge e(i,m.first,m.second);
                edges.push_back(e);
            }
        }
        sort(edges.begin(), edges.end(), comparator());
        vector<Edge> result;
        vector<pair<int,int>> parent(g.V);
        for(int i=0; i<g.V; i++){
            parent[i] = {i,0};
        }
        int i=0;
        cout<<edges.size()<<endl;
        while(result.size() < g.V - 1){
            cout<<"i: "<<i<<" "<<result.size()<<endl;
            Edge e = edges[i];
            int u = e.src;
            int v = e.dest;
            int fu = Find(u,parent);
            int fv = Find(v,parent);
            if(fu != fv){
                Union(fu,fv,parent);
                result.push_back(e);
            }
            i++;
        }
        return result;
    }
};
void test1(){
    Solution s;
    int V = 4;
    GraphW g(V);
    g.addEdge(0, 1, false, 10);
    g.addEdge(0, 2, false, 6);
    g.addEdge(0, 3, false, 5);
    g.addEdge(1, 3, false, 15);
    g.addEdge(2, 3, false, 4);
    vector<Edge> edges = s.MSTKruskalsSetDisjointSetUnionFind(g);
    for(auto &e:edges) {
        cout<<"("<<e.src<<","<<e.dest<<")->"<<e.weight<<endl;
    }
}

#endif /* MST_h */
