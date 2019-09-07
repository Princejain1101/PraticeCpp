//
//  minWindow.hpp
//  leetcode
//
//  Created by Prince Jain on 6/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef minWindow_hpp
#define minWindow_hpp

#include <stdio.h>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
    bool _contains(string s, string t){
        if(t.size() > s.size())
            return false;
        for(auto &c:t){
            auto p = s.find(c);
           // std::cout<<"c: "<<c<<", string: "<<s<<std::endl;
            if(p == string::npos){
                return false;
            }
            s.erase(p,1);
        }
        return true;
    }
    string minWindow(string s, string t) {
        int start=0;
        int end = 0;
        string window = "";
        map<char, int> mark;
        map<char, int> input;
        int marks = 0;
        for(auto &c:t){
            mark[c]=0;
        }
        for(auto &c:s){
            input[c]=0;
        }
        for(auto &c:t){
            mark[c]++;
        }
        while(s.size() - start >=  t.size()){
           // std::cout<<"start:"<<start<<", end:"<<end<<", substr:"<<s.substr(start, end-start+1)<<std::endl;
//            std::cout<<"c: "<<s[end]<<std::endl;
            char c = s[end];
            input[c]++;
            auto it = mark.find(c);
            if(it != mark.end()){
                if(input[c] <= mark[c]){
                    marks++;
                }
            }

            if(end >= s.size()){
                return window;
            } else if(marks >= t.size()) { //if(_contains(s.substr(start, end-start+1), t)){
                while(marks >= t.size()){
//                    std::cout<<"found:  "<<marks<<" ";
//                    std::cout<<s.substr(start, end-start+1)<<std::endl;
                    if(window.size()==0 || window.size() > end-start + 1){
                        window = s.substr(start, end-start+1);
                    }
                    char c = s[start];
                    auto it = mark.find(c);
                    if( it != mark.end()){
               //         std::cout<<"count: "<<input[c]<<" ";
                        if(input[c] <= mark[c]){
                            marks--;
                        }
                        input[c] -= 1;
                    }
               //     std::cout<<"removed: "<<c<<",count: "<<input[c]<<", marks: "<<marks<<std::endl;
                    start++;
                }
                end++;
            } else {
                end++;
            }
        }
        return window;
    }
};
#endif /* minWindow_hpp */
//for(int i=0; i<s.size(); i++){
//    char c = s[i];
//    std::cout<<c<<std::endl;
//            if(t.find(c) != string::npos){
//                if(count.find(c) != count.end()){
//                    count[c]++;
//                }else{
//                    count[c] = 1;
//                }
//                end = i;
//                if(start == -1){
//                    start = i;
//                    index[start] = c;
//                }else{
//                    char d = index[start];
//                    while(count.at(d) > 1){
//                        std::cout<<"index start: "<<index[start]<<", count at: "<<count.at(index[start])<<std::endl;
//                        index.erase(index.begin());
//                        start = index.begin()->first;
//                        count[d]--;
//                        if(count[d]==0){
//                            count.erase(d);
//                        }
//                        d = index[start];
//                    }
//                }
//                std::cout<<start<<" "<<end<<std::endl;
//                if(count.size() == t.size()){
//                    if(window.size()==0){
//                        window = s.substr(start, end-start+1);
//                    }else if(end-start+1<window.size()){
//                        window = s.substr(start, end-start+1);
//                    }
//                    std::cout<<window<<std::endl;
//                }
//                index[i] = c;
//            }
//}

