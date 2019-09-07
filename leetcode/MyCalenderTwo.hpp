//
//  MyCalenderTwo.hpp
//  leetcode
//
//  Created by Prince Jain on 6/21/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef MyCalenderTwo_hpp
#define MyCalenderTwo_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

struct Range{
    int start;
    int end;
    Range():start(-1),end(-1){}
    Range(int s, int e):start(s),end(e){}
    Range(const Range& r){
        start = r.start;
        end = r.end;
    }
    Range& operator=(const Range& r){
        start = r.start;
        end = r.end;
        return *this;
    }
};
bool operator<(const Range &a, const Range &b){
    if(a.start < b.start) return true;
    else return false;
}

class MyCalendarTwo {
    set<Range> firstCalender;
    set<Range> secondCalender;
    bool _ifRangeOverlap(Range &r1, Range &r2){
        if((r2.end <= r1.start) || (r1.end <= r2.start))
            return false;
        return true;
    }
    void _findOverlaps(vector<Range> &overlaps, Range r1, Range r2){
        // r2 inside r1
        if(r1.start <= r2.start && r1.end >= r2.end){
            overlaps.push_back(r2);
            return;
        }
        if(r2.start <= r1.start && r2.end >= r1.end){
            overlaps.push_back(r1);
            return;
        }
        if(r1.start < r2.start){
            Range r(r2.start,r1.end);
            overlaps.push_back(r);
            return;
        }
        if(r2.start < r1.start){
            Range r(r1.start, r2.end);
            overlaps.push_back(r);
            return;
        }
    }
    Range _mergeRanges(Range r1, Range r2){
        Range r(min(r1.start, r2.start), max(r1.end, r2.end));
        return r;
    }
    bool _findInCalender(set<Range> &Calender, Range r, vector<Range> &overlaps){
        cout<<"check range: "<<r.start<<" "<<r.end<<endl;
        bool found = false;
        if(Calender.size()==0){
            cout<<"empty calender"<<endl;
            Calender.insert(r);
            return false;
        }
        auto it = Calender.lower_bound(r);
        Range r1;
        if(it != Calender.begin()){
            it--;
            r1 = *it;
            if(_ifRangeOverlap(r1, r)){
                _findOverlaps(overlaps, r1, r);
                cout<<"overlapping range: "<<r1.start<<" "<<r1.end<<endl;
                found = true;
//                return true;
            }
            it++;
        }
        if(it != Calender.end()){
            r1 = *it;
            if(_ifRangeOverlap(r1, r)){
                _findOverlaps(overlaps, r1, r);
                cout<<"overlapping range: "<<r1.start<<" "<<r1.end<<endl;
                found = true;
            }
        }
        if(found){
            return true;
        }
        cout<<"inserting range: "<<r.start<<" "<<r.end<<endl;
        Calender.insert(r);
        return false;
    }
public:
    MyCalendarTwo() {
        firstCalender.clear();
        secondCalender.clear();
    }
    
    bool book(int start, int end) {
        cout<<"check calender 1"<<endl;
        vector<Range> overlaps;
        if(_findInCalender(firstCalender, Range(start,end), overlaps)){
            cout<<"check calender 2"<<endl;
            if(_findInCalender(secondCalender, Range(start,end))){
                return false;
            }
        }
        return true;
    }
};
void test1(){
    MyCalendarTwo* obj = new MyCalendarTwo();
    bool param_1 = obj->book(10,20);
    if(param_1) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    bool param_2 = obj->book(50,60);
    if(param_2) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    bool param_3 = obj->book(10,40);
    if(param_3) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    bool param_4 = obj->book(5,15);
    if(param_4) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    bool param_5 = obj->book(5,10);
    if(param_5) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    bool param_6 = obj->book(25,55);
    if(param_6) cout<<"true"<<endl;
    else cout<<"false"<<endl;

}
#endif /* MyCalenderTwo_hpp */
