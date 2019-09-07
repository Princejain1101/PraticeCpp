//
//  calcEquation.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef calcEquation_hpp
#define calcEquation_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
struct Node{
    string val;
    map<Node*,double> nb;
    Node(string x):val(x),nb(){}
};
class Solution {
    void _connectNodes(Node* a, Node* b, double cost){
        map<Node*, double> &nb_a = a->nb;
        map<Node*, double> &nb_b = b->nb;
        nb_a.insert(pair<Node*,double>(b,cost));
//        cout<<"inserted: "<<b->val<<" "<<nb_a.at(b)<<", nb_count: "<<nb_a.size()<<endl;
        nb_b.insert(pair<Node*,double>(a,1/cost));
//        cout<<"inserted: "<<a->val<<" "<<nb_b.at(a)<<", nb_count: "<<nb_b.size()<<endl;
    }
    map<string,Node*> _createNodeMap(vector<vector<string>>& equations, vector<double>& values){
        map<string,Node*> nodeset;
        for(int i=0; i<equations.size(); i++){
            string numer = equations[i][0];
            string denom = equations[i][1];
            double cost = values[i];
            cout<<"numer: "<<numer<<", denom: "<<denom<<", cost: "<<cost<<endl;
            if(nodeset.find(numer) == nodeset.end()){
                Node* node = new Node(numer);
                nodeset.insert(pair<string,Node*>(numer,node));
            }
            if(nodeset.find(denom) == nodeset.end()){
                Node* node = new Node(denom);
                nodeset.insert(pair<string,Node*>(denom,node));
            }
            Node* nodeN = nodeset[numer];
            Node* nodeD = nodeset[denom];
            _connectNodes(nodeN, nodeD, cost);
            cout<<numer<<" nb count: "<<nodeN->nb.size()<<endl;
            cout<<denom<<" nb count: "<<nodeD->nb.size()<<endl;
        }
        return nodeset;
    }
    double _searchq(map<string,Node*> &nodemap, string begin, string end, map<string,bool> &done){
        if(nodemap.find(begin) == nodemap.end() || nodemap.find(end) == nodemap.end())
            return -1.0;
        cout<<"found in map"<<endl;
        if(begin == end)
            return 1.0;
        cout<<"not equal"<<endl;
        if(done[begin])
            return -1.0;
        cout<<"not done"<<endl;
        done[begin]=true;
        Node* node = nodemap[begin];
        map<Node*,double> nb = node->nb;
//        cout<<"node: "<<node->val<<", nb count: "<<nb.size()<<endl;
        for(auto &edge : nb){
            string str = edge.first->val;
//            cout<<"str: "<<str<<endl;
            double temp = _searchq(nodemap, str, end, done);
            if(temp!=-1)
                return temp*(edge.second);
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,Node*> nodemap = _createNodeMap(equations, values);
        vector<double> result;
        for(auto & q: queries){
            map<string,bool> done;
            for(auto &s:nodemap){
                done.insert(pair<string,bool>(s.first,false));
            }
            cout<<"q[0]: "<<q[0]<<", q[1]: "<<q[1]<<endl;
            double res = _searchq(nodemap,q[0], q[1], done);
            result.push_back(res);
        }
        return result;
    }
};
void test1(){
    Solution s;
    vector<vector<string>> equation({ {"a", "b"}, {"b", "c"}});
    vector<double> values ({2.0,3.0});
    vector<vector<string>> queries({
        {"a", "c"},
        {"b", "a"},
        {"a", "e"},
        {"a", "a"},
        {"x", "x"}
    });
    vector<double> res = s.calcEquation(equation, values, queries);
    for(auto &i: res){
        cout<<i<<" ";
    }
    cout<<endl;
}
#endif /* calcEquation_hpp */
