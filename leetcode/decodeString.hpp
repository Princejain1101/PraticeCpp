//
//  decodeString.hpp
//  leetcode
//
//  Created by Prince Jain on 6/15/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef decodeString_hpp
#define decodeString_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;
class Solution {
    string _multiplyString(string s, int c){
//        cout<<s<<" "<<c<<endl;
        string ret;
        while(c>0){
            ret.append(s);
            c--;
        }
        return ret;
    }
public:
    int getNumber(string &s, int &index){
        int count=s[index]-'0';
        index++;
        while(s[index] != '['){
            count = count*10 + s[index]-'0';
            index++;
        }
        return count;
    }
    // recursive solution... like DFS.
    // should have less computation time because of no pushing and popping from stack
    // as is in non-recursive solution with stack.
    string decodeStringUtil(string &s, int &index){
        if(index >=s.size())
            return "";
        string temp;
        while(s[index] != ']'){
            if(s[index]-'0' >=0 && s[index]-'0' <10){
                int count = getNumber(s, index);
//                cout<<"count: "<<count<<endl;
                index++;
                string inner = decodeStringUtil(s, index);
//                cout<<"inner: "<<inner<<endl;
                inner = _multiplyString(inner, count);
//                cout<<"inner: "<<inner<<endl;
                temp.append(inner);
            }else{
                temp.append(1,s[index]);
            }
            index++;
            if(index >= s.size())
                break;
        }
        return temp;
    }
    string decodeString(string s){
        int index=0;
        return decodeStringUtil(s, index);
    }
};
void test1(){
    Solution s;
    cout<<s.decodeString("3[a]2[bc]")<<endl;
}
void test2(){
    Solution s;
    cout<<s.decodeString("3[a2[c]]")<<endl;
}
void test3(){
    Solution s;
    cout<<s.decodeString("2[abc]3[cd]ef")<<endl;
}
void test4(){
    Solution s;
    cout<<s.decodeString("100[leetcode]")<<endl;
}

#endif /* decodeString_hpp */

// solution with stack....
//    string decodeString(string s) {
//        stack<char> st;
//        for(auto &c:s){
//            if(c != ']'){
//                st.push(c);
//                continue;
//            }
//            string temp;
//            while(st.top() != '['){
//                temp.append(1,st.top());
//                st.pop();
//            }
//            reverse(temp.begin(),temp.end());
//            st.pop(); // popping '['
//            int count = st.top()-'0';
//            cout<<count<<" ";
//            st.pop();
//            int i=10;
//            while(!st.empty() && st.top()-'0'>=0 && st.top()-'0'<10){
//                count = count + (st.top()-'0')*i;
//                i = i*10;
//                st.pop();
//                cout<<count<<" ";
//            }
//            cout<<endl;
//            temp = _multiplyString(temp, count);
//            for(auto &c:temp){
//                st.push(c);
//            }
//        }
//        string ret;
//        while(!st.empty()){
//            ret.append(1,st.top());
//            st.pop();
//        }
//        reverse(ret.begin(),ret.end());
//        return ret;
//    }
