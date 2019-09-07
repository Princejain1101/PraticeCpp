//
//  partitionLabels.h
//  leetcode
//
//  Created by Prince Jain on 7/8/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef partitionLabels_h
#define partitionLabels_h
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;
class Solution {
    void _mergeSets(vector<string>& resultSet, char newc){
        int n = (int)resultSet.size();
        int i = n-1;
//        cout<<"n: "<<n<<", "<<newc<<endl;
        for(i=n-1; i>=0; i--){
            string cs = resultSet[i];
            if(cs.find(newc) != string::npos)
                break;
        }
        if(i<0){
            string s(1,newc);
            resultSet.push_back(s);
            return;
        }
        string rs(1,newc);
        
        int k = n-1;
        while(k >= i){
            string cs = resultSet[k];
            rs = cs + rs;
            resultSet.pop_back();
            k--;
        }
        resultSet.push_back(rs);
    }
    
public:
    // n^2 solution
    vector<int> partitionLabels1(string S) {
        vector<string> resultSet;
        vector<int> result;
        for(int i=0; i<(int)S.size(); i++){
            _mergeSets(resultSet, S[i]);
        }
        for(int i=0; i<(int)resultSet.size(); i++){
//            cout<<resultSet[i]<<" "<<(int)resultSet[i].size()<<endl;
            result.push_back((int)resultSet[i].size());
        }
        return result;
    }
    
    // O(n) solution
    vector<int> partitionLabels(string S){
        int n = (int)S.size();
        vector<int> charLastIndex(256,0);
        for(int i=0; i<n; i++){
            charLastIndex[S[i]] = i;
        }
        vector<int> result;
        int start=0;
        while(start<n){
            int end = charLastIndex[S[start]];
            int index = start;
            while(index < end){
                end = max(end, charLastIndex[S[index]]);
                index++;
            }
            result.push_back(end-start+1);
            start = end+1;
        }
        return result;
    }
};
void test1(){
    Solution s;
    vector<int> res = s.partitionLabels("ababcbacadefegdehijhklij");
    for(auto &i:res) cout<<i<<" ";
    cout<<endl;
}

#endif /* partitionLabels_h */
