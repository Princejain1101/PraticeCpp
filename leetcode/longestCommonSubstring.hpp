//
//  longestCommonSubstring.hpp
//  leetcode
//
//  Created by Prince Jain on 6/29/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef longestCommonSubstring_hpp
#define longestCommonSubstring_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    bool _ifContains(string s1, string s2){
        if(s1.size()==0 && s2.size()==0) return true;
        if(s1.size()==0) return false;
        if(s2.size()==0) return true;
        int m = (int)s1.size();
        int n = (int)s2.size();
        
        int start=0;
        int count=0;
        int i=0; int j=0;
        while(i<m && j < n){
//            cout<<s1[i]<<" "<<s2[j]<<endl;
            if(s1[i]==s2[j]){
                count++;
                if(count==n) {
                    cout<<s2<<" at: "<<i-j<<endl;
                    i = start+1; j=0;
                }
                i++;j++; continue;
            }
            j=0;
            start++;
            while(start<m && s1[start]!=s2[j]){
                start++;
            }
            i = start;
            count=0;
        }
        return false;
    }

    int LCS(string s1, string s2) {
        int m = (int)s1.size();
        int n = (int)s2.size();
        int s2index=0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int result=0;
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j] > result){
                        result = dp[i][j];
                        s2index = j-1;
                    }
                    
                }else{
                    dp[i][j]=0;
                }
            }
        }
        cout<<s2.substr(s2index-result+1,result)<<endl;
        return result;
    }
    // wrong implementation....
    int LCS2(string s1, string s2) {
        int m = (int)s1.size();
        int n = (int)s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                dp[i][j]=0;
                if(i==0 || j==0){
                    dp[i][j]=0;
                    continue;
                }else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return max(dp[m][n], max(dp[m-1][n],dp[m][n-1]));
    }
    int LCSRecr(string s1, string s2, int i, int j, int count) {
//        cout<<"i: "<<i<<", j: "<<j<<endl;
        if(i==0 || j==0)
            return count;
        if(s1[i-1]==s2[j-1]){
            count = LCSRecr(s1, s2, i-1, j-1, count+1);
        }
        count = max(count, max(LCSRecr(s1, s2, i-1, j, 0),LCSRecr(s1, s2, i, j-1, 0)));
        return count;
    }
    int LCSRecrSubsequence(string s1, string s2, int i, int j, int count) {
        //        cout<<"i: "<<i<<", j: "<<j<<endl;
        if(i==0 || j==0){
//            if(count>0) cout<<"count: "<<count<<endl;
            return count;
        }
        int count2=count;
        if(s1[i-1]==s2[j-1]){
//            cout<<s1[i-1]<<" = "<<s2[j-1]<<endl;
            count2 = LCSRecrSubsequence(s1, s2, i-1, j-1, count+1);
        }
        count2 = max(count2,max(
                                LCSRecrSubsequence(s1, s2, i-1, j, count),
                                LCSRecrSubsequence(s1, s2, i, j-1, count)
                                ));
        return count2;
    }
    int LCRRecrSubsequence2(string s1, string s2, int i, int j){
        if(i==0 || j==0){
            return 0;
        }
        int count=0;
        if(s1[i-1] == s2[j-1]){
            count = 1 + LCRRecrSubsequence2(s1, s2, i-1, j-1);
        }else{
            count = max(LCRRecrSubsequence2(s1, s2, i, j-1),LCRRecrSubsequence2(s1, s2, i-1, j));
        }
        return count;
    }
};
void test1(){
    Solution s;
    cout<<s.LCS("OldSite:GeeksforGeeks.org", "NewSite:GeeksQuiz.com")<<endl;
    cout<<s.LCS2("OldSite:GeeksforGeeks.org", "NewSite:GeeksQuiz.com")<<endl;
    string s1("abcdxyzabd");
    string s2("xyzad");
    cout<<s.LCSRecr(s1, s2, (int)s1.size(), (int)s2.size(), 0)<<endl;
    cout<<s.LCSRecrSubsequence(s1, s2, (int)s1.size(), (int)s2.size(), 0)<<endl;
    cout<<s.LCRRecrSubsequence2(s1, s2, (int)s1.size(), (int)s2.size())<<endl;
//    cout<<s._ifContains(s1, "ab")<<endl;
}
#endif /* longestCommonSubstring_hpp */
