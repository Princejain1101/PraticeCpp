//
//  minAreaRect.hpp
//  leetcode
//
//  Created by Prince Jain on 6/22/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef minAreaRect_hpp
#define minAreaRect_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
struct Point{
    int x;
    int y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point(const Point & p){
        x = p.x;
        y = p.y;
    }
    Point& operator=(const Point& p){
        x = p.x;
        y = p.y;
        return *this;
    }
    bool operator==(Point &p)const{
        if(p.x==x && p.y==y) return true;
        else return false;
    }
};
class Solution {
    Point _getFourth(Point ap, Point bp, Point cp){
        Point a,b,c,d;
        if(ap.x != bp.x && ap.y != bp.y){
            a = ap; b = bp; c = cp;
        }
        if(ap.x != cp.x && ap.y != cp.y){
            a = ap; b = cp; c = bp;
        }
        if(cp.x != bp.x && cp.y != bp.y){
            a = bp; b = cp; c = ap;
        }
        if(Point(a.x,b.y)==c) d = Point(b.x,a.y);
        else d = Point(a.x,b.y);
        return d;
    }
    int _getArea(Point a, Point b, Point c){
        int width=0;
        int height=0;
        if(a.x==b.x){
            height=a.y-b.y;
        }
        if(c.x==b.x){
            height=c.y-b.y;
        }
        if(a.x==c.x){
            height=a.y-c.y;
        }
        if(a.y==b.y){
            width=a.x-b.x;
        }
        if(a.y==c.y){
            width=a.x-c.x;
        }
        if(c.y==b.y){
            width=c.x-b.x;
        }
//        cout<<"height: "<<height<<", width: "<<width<<endl;
        int area = height*width;
        if(area<0) area *=-1;
        return area;
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        Point first,second,third,fourth;
        int minArea = INT_MAX;
        for(int i=0; i<points.size()-3; i++){
            first = Point(points[i][0],points[i][1]);
            for(int j=i+1; j<points.size()-2; j++){
                second = Point(points[j][0],points[j][1]);
                bool xcommon = first.x == second.x;
                bool ycommon = first.y == second.y;
                bool diagonal = (first.x != second.x) && (first.y != second.y);
                for(int k=j+1; k<points.size()-1; k++){
                    third = Point(points[k][0],points[k][1]);
                    if(xcommon){
                        if(third.y != first.y && third.y != second.y)
                            continue;
                    }
                    if(ycommon){
                        if(third.x != first.x && third.x != second.x)
                            continue;
                    }
                    if(diagonal){
                        if(!((third.x == first.x && third.y == second.y) ||
                           (third.y == first.y && third.x == second.x))){
                            continue;
                        }
                    }
                    for(int m=k+1; m<points.size(); m++){
                        Point fourth = _getFourth(first, second, third);
                        Point temp(points[m][0],points[m][1]);
                        if(fourth == temp){
                            int area = _getArea(first, second, third);
                            minArea = min(minArea,area);
                        }
                    }
                }
            }
        }
        if(minArea == INT_MAX)
            return 0;
        else return minArea;
    }
};
void test1(){
    Solution s;
    vector<vector<int>> points({
        {1,1},{1,3},{3,1},{3,3},{2,2}
    });
    cout<<s.minAreaRect(points)<<endl;
}
void test2(){
    Solution s;
    vector<vector<int>> points({
        {1,1},{1,3},{3,1},{3,3},{4,1},{4,3}
    });
    cout<<s.minAreaRect(points)<<endl;
}
#endif /* minAreaRect_hpp */
