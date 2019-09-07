//
//  linesIntersect.hpp
//  leetcode
//
//  Created by Prince Jain on 6/30/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef linesIntersect_hpp
#define linesIntersect_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
struct Point{
    int x;
    int y;
};
class Solution {
    // 0  collinear
    // 1  clockwise
    // 2  counter-clockwise
    int checkOrientation(Point p1, Point q1, Point r){
        int val = (q1.y-p1.y)*(q1.x-r.x) - (q1.x-p1.x)*(q1.y-r.y);
        if(val==0) return 0;
        return (val>0) ? 1 : 2;
    }
    // check if point r is on p1-q1
    bool onSegment(Point p1, Point q1, Point r){
        if(r.x <= max(p1.x,q1.x) && r.x >= min(p1.x,q1.x) &&
           r.y <= max(p1.y,q1.y) && r.y >= min(p1.y,q1.y))
            return true;
        return false;
    }
public:
    int doIntersect(Point p1, Point q1, Point p2, Point q2) {
        int o1 = checkOrientation(p1, q1, p2);
        int o2 = checkOrientation(p1, q1, q2);
        int o3 = checkOrientation(p2, q2, p1);
        int o4 = checkOrientation(p2, q2, q1);
        if(o1 != o2 && o3 != o4) return true;
//        cout<<"collinear"<<endl;
        // otherwise points are collinear
        if(o1==0 && onSegment(p1, q1, p2)) return true;
        if(o2==0 && onSegment(p1, q1, q2)) return true;
        if(o3==0 && onSegment(p2, q2, p1)) return true;
        if(o4==0 && onSegment(p2, q2, q1)) return true;
        
        return false;
    }
    vector<Point> convexHull(vector<Point> points){
        int n = (int)points.size();
        int p=0;
        for(int i=1; i<n; i++){
            if(points[i].x < points[p].x)
                p = i;
        }
        vector<Point> hull;
        int l = p;
        do{
            // put the leftmost point on convex hull
            hull.push_back(points[p]);
            int q = (p+1)%n;
            // find next point in convex fashion
            for(int i=0; i<n; i++){
                if(checkOrientation(points[p], points[q], points[i]) == 2)
                    q = i;
            }
            p = q;
        }while(p != l);
        return hull;
    }
};
void test1(){
    Solution s;
    struct Point p1 = {1, 1}, q1 = {10, 1};
    struct Point p2 = {1, 2}, q2 = {10, 2};
    s.doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
    
    p1 = {10, 0}; q1 = {0, 10};
    p2 = {0, 0}; q2 = {10, 10};
    s.doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
    
    p1 = {-5, -5}; q1 = {0, 0};
    p2 = {1, 1}; q2 = {10, 10};
    s.doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
    
    vector<Point> points{{0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3}};
    vector<Point> hull = s.convexHull(points);
    for(auto &p:hull) cout<<"("<<p.x<<","<<p.y<<"), ";
    cout<<endl;
}
#endif /* linesIntersect_hpp */
