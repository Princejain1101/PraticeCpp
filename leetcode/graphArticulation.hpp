//
//  graphArticulation.hpp
//  leetcode
//
//  Created by Prince Jain on 7/4/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef graphArticulation_hpp
#define graphArticulation_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include "graph.h"

using namespace std;
class Solution {
    void _articulationPointUtil(Graph &g,
                                vector<bool>& visited,
                                vector<int>& parent,
                                vector<int>& discovery,
                                vector<int>& lowDiscovery,
                                vector<int>& APs,
                                int u
                                ){
        static int count=0;
        visited[u]=true;
        discovery[u] = count;
        lowDiscovery[u] = count;
        count++;
        int children=0;
        for(auto &i:g.edges[u]){
            if(visited[i] == false){
                children++;
                parent[i] = u;
                _articulationPointUtil(g, visited, parent, discovery, lowDiscovery, APs, i);
                lowDiscovery[u] = min(lowDiscovery[u], lowDiscovery[i]);
                if(parent[u]==-1 && children>1){
                    APs.push_back(u);
                }
                if(parent[u] != -1 && lowDiscovery[i] >= discovery[u]){
                    APs.push_back(u);
                }
            }else{
                if(i != parent[u]){
                    lowDiscovery[u] = min(lowDiscovery[u], discovery[i]);
                }
            }
        }
    }
    void _bridgesInGraphUtil(Graph &g,
                             vector<bool>& visited,
                             vector<int>& parent,
                             vector<int>& discovery,
                             vector<int>& lowDiscovery,
                             vector<pair<int,int>>& bridges,
                             int u
                             ){
        static int count=0;
        visited[u] = true;
        discovery[u] = count;
        lowDiscovery[u] = count;
        count++;
        for(auto &v: g.edges[u]){
            if(!visited[v]){
                parent[v] = u;
                _bridgesInGraphUtil(g, visited, parent, discovery, lowDiscovery, bridges, v);
                lowDiscovery[u] = min(lowDiscovery[u], lowDiscovery[v]);
                if(lowDiscovery[v] > discovery[u]){
                    bridges.push_back(pair<int,int>(u,v));
                }
            }else{
                if(v != parent[u])
                    lowDiscovery[u] = min(lowDiscovery[u], discovery[v]);
            }
        }
    }
    void _fillStackDFS(Graph &g, int u, vector<bool> &visited, stack<int> &finishStack){
        visited[u] = true;
//        cout<<"edges count: "<<u<<" "<<g.edges[u].size()<<endl;
        for(auto &v: g.edges[u]){
            if(!visited[v]){
//                cout<<"visiting: "<<u<<"->"<<v<<endl;
                _fillStackDFS(g, v, visited, finishStack);
            }
        }
        finishStack.push(u);
    }
    void _fillSSC(Graph &g, int u, vector<bool>& visited, vector<int>& SSC){
        visited[u] = true;
        SSC.push_back(u);
        for(auto &v: g.edges[u]){
            if(!visited[v])
                _fillSSC(g, v, visited, SSC);
        }
    }
public:
    vector<int> articulationPoint(Graph &g) {
        int V = g.V;
        vector<int> parent(V,-1);
        vector<int> discovery(V);
        vector<int> lowDiscovery(V);
        vector<bool> visited(V,false);
        vector<int> APs;
        for(int i=0; i<V; i++){
            if(!visited[i])
                _articulationPointUtil(g, visited, parent, discovery, lowDiscovery, APs, i);
        }
        return APs;
    }
    vector<pair<int,int>> bridgesInGraph(Graph &g){
        int V = g.V;
        vector<int> parent(V,-1);
        vector<int> discovery(V);
        vector<int> lowDiscovery(V);
        vector<bool> visited(V,false);
        vector<pair<int,int>> bridges;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                _bridgesInGraphUtil(g, visited, parent, discovery, lowDiscovery, bridges, i);
            }
        }
        return bridges;
    }
    vector<vector<int>> stronglyConnectedGraphs(Graph& g){
        // DFS to fill up the stack in order of finish time such
        // that finish time of vertex that connectes to other SSCs
        // is greater than its other vertices.
        stack<int> finishStack;
        vector<bool> visited(g.V, false);
        for(int i=0; i<g.V; i++){
            if(!visited[i]){
                _fillStackDFS(g, i, visited, finishStack);
            }
        }
//        cout<<"stack size: "<<finishStack.size()<<endl;
        Graph gt = g.transpose();
        vector<vector<int>> SSCs;
        vector<bool> visited2(g.V,false);
        while(!finishStack.empty()){
            int u = finishStack.top();
            finishStack.pop();
            if(!visited2[u]){
                vector<int> SSC;
                _fillSSC(gt, u, visited2, SSC);
                SSCs.push_back(SSC);
            }
        }
        return SSCs;
    }
};
void test1(){
    Solution s;
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    cout<<"G1 APs: ";
    vector<int> APs = s.articulationPoint(g1);
    for(auto &p: APs) cout<<p<<", ";
    cout<<endl;
    cout<<"G1 bridges: ";
    vector<pair<int,int>> bridges1 = s.bridgesInGraph(g1);
    for(auto &b: bridges1) cout<<"("<<b.first<<"->"<<b.second<<"), ";
    cout<<endl;
    cout<<endl;

    
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    cout<<"G2 APs: ";
    vector<int> APs2 = s.articulationPoint(g2);
    for(auto &p: APs2) cout<<p<<", ";
    cout<<endl;
    cout<<"G2 bridges: ";
    vector<pair<int,int>> bridges2 = s.bridgesInGraph(g2);
    for(auto &b: bridges2) cout<<"("<<b.first<<"->"<<b.second<<"), ";
    cout<<endl;
    cout<<endl;

    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    cout<<"G3 APs: ";
    vector<int> APs3 = s.articulationPoint(g3);
    for(auto &p: APs3) cout<<p<<", ";
    cout<<endl;
    cout<<"G3 bridges: ";
    vector<pair<int,int>> bridges3 = s.bridgesInGraph(g3);
    for(auto &b: bridges3) cout<<"("<<b.first<<"->"<<b.second<<"), ";
    cout<<endl;
    cout<<endl;

    
    Graph gD(5);
    gD.addEdge(1, 0, true);
    gD.addEdge(0, 2, true);
    gD.addEdge(2, 1, true);
    gD.addEdge(0, 3, true);
    gD.addEdge(3, 4, true);
    vector<vector<int>> SSCs = s.stronglyConnectedGraphs(gD);
    cout<<"Gdirected Strongly Connected components"<<endl;
    for(auto &SSC: SSCs){
        for(auto &v:SSC) cout<<v<<"->";
        cout<<endl;
    }
}
#endif /* graphArticulation_hpp */
