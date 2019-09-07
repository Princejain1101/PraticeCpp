//
//  rangeSumQuery2D.hpp
//  leetcode
//
//  Created by Prince Jain on 6/20/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef rangeSumQuery2D_hpp
#define rangeSumQuery2D_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct point{
    int x;
    int y;
    point(int _x, int _y):x(_x),y(_y){}
    point(const point& p):x(p.x),y(p.y){}
    bool operator==(const point &p) const {
        if(x==p.x && y==p.y)
            return true;
        return false;
    }
};
struct corner{
    point a;
    point b;
    corner(point _a, point _b):a(_a),b(_b){}
    bool operator==(const corner& c) const {
        if((c.a == a) && (c.b == b))
            return true;
        else
            return false;
    }
};
namespace std{
    template<>
    struct hash<corner>{
        uint64_t operator()(const corner& c) const {
            return ((uint64_t)c.a.x)<<32 | (uint64_t)c.b.x;
        }
    };
    template<>
    struct hash<point>{
        uint64_t operator()(const point& p) const {
            return ((uint64_t)p.x)<<32 | (uint64_t)p.y;
        }
    };
}
class NumMatrix {
    unordered_map<corner, int> cornersum;
//    unordered_map<point, unordered_set<corner>> pointInCorner;
    vector<vector<int>> matrix;
//    vector<corner> cornervec;
//    vector<int> sums;
    bool _inCorner(const corner &c, const point &p) const{
        point lefttop = c.a;
        point rightbottom = c.b;
        if(p.x >= lefttop.x && p.x <= rightbottom.x &&
           p.y >= lefttop.y && p.y <= rightbottom.y)
            return true;
        return false;
    }
public:
    NumMatrix(vector<vector<int>>& matrix):matrix(matrix){}
    
    void update(int row, int col, int val) {
        if(row >= matrix.size() || row < 0)
            return;
        if(col >= matrix[0].size() || col < 0)
            return;
        if(matrix[row][col] == val)
            return;
        point p(row,col);
//        if(pointInCorner.find(p)==pointInCorner.end()){
//            matrix[row][col] = val;
//            return;
//        }
//        unordered_set<corner> &cornerset = pointInCorner[p];
//        for(auto &corner : cornerset){
//            if(cornersum.find(corner)==cornersum.end())
//                continue;
//            cornersum[corner] = cornersum[corner] + val - matrix[row][col];
//        }
        for(auto &cmap: cornersum){
            if(_inCorner(cmap.first, p)){
                cmap.second -= matrix[row][col];
                cmap.second += val;
            }
        }
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        point a(row1,col1);
        point b(row2,col2);
        corner c(a,b);
        if(cornersum.find(c) != cornersum.end()){
//            cout<<"found corner "<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<endl;
            return cornersum[c];
        }
        cornersum[c]=0;
        int sum=0;
//        cout<<"calculating sum corner "<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<endl;
//        cout<<"matrix size: "<<matrix.size()<<" "<<matrix[0].size()<<endl;

        for(int i=row1; i<matrix.size() && i<=row2;i++){
//            cout<<"i: "<<i<<endl;
            for(int j=col1; j<matrix[0].size() && j<=col2;j++){
                
                sum += matrix[i][j];
//                cout<<"i: "<<i<<", j: "<<j<<", matrix[i][j]: "<<matrix[i][j]<<endl;
//                point p(i,j);
//                pointInCorner[p].insert(c);
            }
        }
        cornersum[c]=sum;
        return sum;
    }
};
void test1(){
    cout<<"test1"<<endl;
    vector<vector<int>> matrix({
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    });
    NumMatrix *obj = new NumMatrix(matrix);
    cout<<obj->sumRegion(2, 1, 4, 3)<<endl;
    obj->update(3, 2, 2);
    cout<<obj->sumRegion(2, 1, 4, 3)<<endl;
}
void test2(){
    cout<<"test2"<<endl;
    vector<vector<int>> matrix({
        {1},{2}
    });
//    cout<<matrix.size()<<" "<<matrix[0].size()<<endl;
    NumMatrix *obj = new NumMatrix(matrix);
    cout<<obj->sumRegion(0, 0, 0, 0)<<endl;
    cout<<obj->sumRegion(1, 0, 1, 0)<<endl;
    cout<<obj->sumRegion(0, 0, 1, 0)<<endl;
    obj->update(0, 0, 3);
    obj->update(1, 0, 5);
    cout<<obj->sumRegion(0, 0, 1, 0)<<endl;
}
void test3(){
    cout<<"test3"<<endl;
    vector<vector<int>> matrix({
        {2,4},{-3,5}
    });
//    cout<<matrix.size()<<" "<<matrix[0].size()<<endl;
    NumMatrix *obj = new NumMatrix(matrix);
    obj->update(0, 1, 3);
    obj->update(1, 1, -3);
    obj->update(0, 1, 1);
    cout<<obj->sumRegion(0, 0, 1, 1)<<endl;
}
#endif /* rangeSumQuery2D_hpp */
