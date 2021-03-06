//
//  removeStones.hpp
//  leetcode
//
//  Created by Prince Jain on 6/16/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef removeStones_hpp
#define removeStones_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
struct point {
    int x;
    int y;
    point(int _x, int _y):x(_x),y(_y){}
    point(point &_p) {
        x = _p.x;
        y = _p.y;
    }
    point& operator=(point &_p) {
        x = _p.x;
        y = _p.y;
        return *this;
    }
};
struct Node{
    point p;
    set<Node*> nb;
    Node(point _p):p(_p){}
};
void printNode(Node* node){
    if(node ==nullptr)
        return;
    cout<<"("<<node->p.x<<","<<node->p.y<<"): ";
    for(auto&n: node->nb){
        cout<<"("<<n->p.x<<","<<n->p.y<<"),";
    }
    cout<<endl;
}

struct comparator{
    bool operator()(const Node* a, const Node* b) {
        if(a==nullptr || b==nullptr)
            return false;
        if(a->nb.size() > b->nb.size())
            return false;
        else
            return true;
    }
}comp;
void _connectNodes(vector<Node*> nodevec, Node* b){//, set<Node*,comparator> &nodeset){
//    for(auto &n:nodeset){
//        printNode(n);
//    }
    
    cout<<"connecting nodes: ("<<b->p.x<<","<<b->p.y<<"): ";

    for(auto & a: nodevec){
        a->nb.insert(b);
//        cout<<"("<<a->p.x<<","<<a->p.y<<"),";
//        if(nodeset.find(a) == nodeset.end()){
//            cout<<"not found"<<endl;
//        }
//        nodeset.erase(nodeset.find(a));
//        nodeset.insert(a);
        b->nb.insert(a);
    }
    cout<<endl;


    
}
void _removeConnection(Node* n){
    for(auto &node: n->nb){
        if(node->nb.find(n) == node->nb.end())
            cout<<"not found"<<endl;
        node->nb.erase(node->nb.find(n));
    }
    n->nb.clear();
}
vector<Node*> _createEdgeCountSortedGraph(vector<vector<int>> & stones){
    vector<Node*> nodeset;
    map<int,vector<Node*>> mapx;
    map<int,vector<Node*>> mapy;
    for(int i=0; i<stones.size(); i++){
        int x = stones[i][0];
        int y = stones[i][1];
        point p(x,y);
        Node* node = new Node(p);
        if(mapx.find(x) == mapx.end()){
            vector<Node*> nodevec({node});
            mapx.insert(pair<int,vector<Node*>>(x,nodevec));
        }else{
            _connectNodes(mapx[x], node);//,nodeset);
            mapx[x].push_back(node);
        }
        if(mapy.find(y) == mapy.end()){
            vector<Node*> nodevec({node});
            mapy.insert(pair<int,vector<Node*>>(y,nodevec));
        }else{
            _connectNodes(mapy[y], node);//, nodeset);
            mapx[y].push_back(node);
        }
        cout<<"pushing back: ("<<node->p.x<<","<<node->p.y<<")"<<endl;
        nodeset.push_back(node);
    }
    return nodeset;
}
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<Node*> nodeset = _createEdgeCountSortedGraph(stones);
        for(auto &n:nodeset){
            printNode(n);
        }
        sort(nodeset.begin(), nodeset.end(), comp);
//        for(auto &n:nodeset){
//            printNode(n);
//        }

        int removedStones=0;
        for(auto &n:nodeset){
            if(n->nb.size()==0)
                continue;
            _removeConnection(n);
            removedStones++;
        }
        return removedStones;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> stones ({{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}});
        cout<<s.removeStones(stones)<<endl;
}
void test2(){
    Solution s;
    vector<vector<int>> stones ({{0,0},{0,2},{1,1},{2,0},{2,2}});
    cout<<s.removeStones(stones)<<endl;
}
void test3(){
    Solution s;
    vector<vector<int>> stones ({{0,0}});
    cout<<s.removeStones(stones)<<endl;
}
void test4(){
    Solution s;
    vector<vector<int>> stones ({{0,1},{1,2},{1,3},{3,3},{2,3},{0,2}});
    cout<<s.removeStones(stones)<<endl;
}
void test5(){
    Solution s;
    vector<vector<int>> stones ({
{46,42},{90,187},{0,175},{46,135},{162,97},{42,20},{25,195},{109,117},{109,236},{187,65},{178,194},{5,12},{220,15},{124,270},{256,40},{138,163},{140,131},{132,224},{265,250},{204,244},{249,145},{167,44},{269,68},{26,54},{59,51},{172,87},{119,31},{279,284},{6,287},{39,179},{247,224},{277,299},{78,67},{226,88},{94,57},{103,73},{115,232},{248,0},{64,117},{94,67},{79,224},{15,43},{105,176},{15,178},{18,242},{154,243},{238,125},{89,259},{142,287},{53,277},{98,82},{29,62},{258,232},{264,157},{14,96},{284,283},{189,99},{189,214},{272,77},{282,140},{214,85},{27,279},{232,98},{161,58},{186,157},{120,16},{96,172},{111,6},{275,185},{226,194},{0,297},{96,130},{97,244},{286,186},{14,95},{258,201},{208,190},{63,137},{48,177},{87,238},{105,126},{249,239},{236,42},{85,158},{47,251},{201,270},{84,31},{58,22},{149,189},{186,156},{49,194},{251,266},{5,159},{109,162},{41,152},{28,23},{94,87},{132,251},{191,209},{251,37},{170,215},{130,229},{235,77},{211,107},{38,197},{257,169},{113,179},{9,270},{84,56},{263,292},{198,90},{286,248},{265,108},{171,4},{76,90},{241,248},{215,224},{278,257},{113,219},{140,54},{247,57},{66,262},{255,208},{7,16},{34,281},{230,278},{1,192},{292,52},{9,281},{169,140},{187,253},{219,97},{220,145},{239,98},{236,288},{238,68},{228,270},{34,1},{159,255},{199,127},{159,153},{186,144},{243,276},{239,175},{12,131},{238,267},{196,41},{10,112},{184,111},{14,262},{284,181},{77,145},{149,260},{153,119},{155,229},{200,187},{193,126},{150,212},{230,265},{83,263},{137,232},{240,40},{202,18},{6,276},{51,249},{208,245},{156,58},{41,51},{22,127},{111,26},{250,91},{44,205},{272,222},{182,48},{257,259},{265,284},{97,10},{60,22},{18,235},{223,191},{177,92},{161,282},{207,99},{209,256},{120,240},{276,128},{3,169},{102,109},{240,275},{50,288},{65,216},{230,8},{6,289},{89,89},{140,280},{283,9},{122,19},{236,246},{165,190},{174,284},{99,182},{270,108},{205,78},{227,161},{16,283},{99,156},{101,228},{143,179},{286,50},{19,72},{45,226},{27,88},{27,37},{175,192},{17,34},{49,249},{182,166},{120,32},{182,63},{270,42},{113,199},{52,29},{255,77},{60,109},{188,26},{88,21},{172,53},{135,67},{70,82},{16,296},{84,65},{195,125},{93,75},{199,232},{106,124},{284,280},{190,76},{209,73},{214,86},{34,31},{17,61},{120,176},{252,233},{68,48},{174,161},{155,171},{225,64},{105,77},{204,239},{195,54},{299,215},{108,167},{242,283},{204,197},{12,241},{204,42},{31,189},{149,214},{33,17},{225,260},{70,254},{222,267},{225,103},{276,283},{236,84},{272,166},{137,53},{133,167},{99,8},{286,190},{104,70},{57,73},{272,140},{190,239},{78,133},{236,173},{226,171},{294,54},{201,237},{48,171},{144,144},{134,260},{86,17},{171,3},{55,244},{232,115},{227,121},{85,2},{6,109},{45,62},{146,136},{220,211},{149,276},{252,68},{298,11},{75,140},{260,174},{126,29},{190,150},{123,209},{290,35},{264,6},{5,188},{84,68},{65,52},{138,75},{37,45},{235,86},{223,251},{95,23},{99,80},{149,172},{182,222},{71,161},{191,83},{220,279},{171,137},{112,215},{118,68},{110,97},{84,220},{4,3},{296,187},{73,204},{266,37},{255,264},{211,211},{244,244},{41,137},{171,91},{97,253},{40,79},{22,276},{247,254},{128,90},{184,39},{42,77},{170,6},{172,294},{141,164},{224,299},{185,129},{55,123},{204,233},{60,102},{4,297},{79,159},{260,186},{175,73},{286,196},{83,101},{103,136},{128,162},{295,34},{150,63},{155,140},{150,36},{140,81},{196,118},{90,74},{219,191},{145,17},{225,95},{142,107},{262,137},{205,238},{105,27},{229,194},{231,162},{115,21},{280,126},{136,76},{152,166},{132,254},{37,34},{11,51},{117,184},{210,110},{167,251},{174,18},{67,180},{298,239},{22,201},{70,280},{180,207},{213,39},{80,95},{20,170},{182,108},{63,116},{92,6},{229,8},{250,276},{159,9},{298,204},{208,118},{180,39},{67,189},{296,113},{244,4},{132,231},{217,165},{3,245},{201,42},{78,12},{145,99},{274,9},{110,73},{57,202},{211,92},{254,277},{111,222},{248,122},{162,106},{10,222},{107,144},{221,252},{215,182},{192,178},{285,1},{152,120},{151,0},{225,62},{87,120},{211,127},{39,245},{186,283},{232,53},{50,100},{287,216},{294,186},{46,8},{85,51},{91,47},{257,142},{109,284},{242,6},{296,284},{209,54},{11,141},{192,226},{240,240},{51,294},{191,41},{191,208},{266,172},{91,262},{160,105},{150,104},{166,140},{184,36},{244,77},{236,34},{251,26},{18,14},{166,158},{259,264},{52,71},{270,186},{77,210},{220,155},{28,151},{139,167},{158,154},{107,164},{198,125},{179,217},{285,13},{119,176},{73,146},{183,262},{219,221},{170,223},{165,9},{282,224},{79,2},{124,138},{2,213},{112,23},{125,139},{106,85},{166,2},{284,115},{237,54},{23,157},{236,70},{26,284},{52,146},{180,79},{95,160},{240,88},{248,39},{278,68},{212,21},{237,132},{131,254},{214,232},{42,5},{299,43},{95,114},{101,107},{233,232},{196,214},{67,61},{25,126},{225,96},{67,164},{110,253},{155,161},{269,226},{191,68},{173,154},{82,186},{290,27},{159,278},{157,247},{277,261},{286,193},{230,251},{38,100},{0,173},{60,182},{90,2},{186,95},{291,159},{297,191},{284,218},{154,141},{176,125},{292,138},{298,293},{1,43},{15,258},{253,127},{255,154},{287,113},{91,94},{260,30},{168,164},{8,248},{144,196},{74,101},{35,95},{209,44},{18,114},{51,32},{102,236},{184,132},{268,265},{189,114},{210,69},{110,62},{208,93},{68,187},{10,274},{89,252},{113,79},{68,202},{46,106},{63,146},{137,175},{166,193},{98,139},{198,21},{73,235},{95,67},{37,124},{132,267},{275,88},{87,92},{270,153},{54,143},{92,2},{11,70},{30,31},{85,45},{35,51},{206,48},{182,208},{180,126},{167,83},{125,259},{57,93},{133,292},{187,297},{263,15},{125,168},{195,287},{89,24},{217,83},{273,24},{7,10},{88,277},{43,147},{218,242},{18,133},{156,299},{113,158},{170,155},{194,140},{132,181},{128,253},{217,178},{209,125},{187,185},{52,129},{11,259},{120,132},{235,14},{200,60},{0,137},{274,161}
    });
    cout<<s.removeStones(stones)<<endl;
}

#endif /* removeStones_hpp */
