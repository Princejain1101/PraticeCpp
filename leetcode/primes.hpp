//
//  primes.hpp
//  leetcode
//
//  Created by Prince Jain on 6/30/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef primes_hpp
#define primes_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
class Solution {
public:
    bool ifPrime(int n){
        if(n<=1) return false;
        if(n<=3) return true;
        for(int i=2; i*i<=n; i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
    bool ifPrime2(int n, vector<int>& primes){
        if(n<=1) return false;
        if(n<=3) return true;
        for(int i=0; i<(int)primes.size(); i++){
            int prime = primes[i];
            if(prime*prime > n) return true;
            if(n%prime==0) return false;
        }
        return true;
    }
    vector<int> getPrimes(int n){
        vector<int> primes;
        if(n<=1) return primes;
        if(n>=2) primes.push_back(2);
        if(n>=3) primes.push_back(3);
        
        for(int i=5; i<=n; i++){
            if(ifPrime2(i, primes))
                primes.push_back(i);
        }
        return primes;
    }
    vector<int> getPrimesSieveOfEratosthenes(int n){
        vector<bool> primes(n+1,true);
        primes[0]=false;
        primes[1]=false;
        
        int p = 2;
        while(p*p<=n){
            for(int i=p*p; i<=n; i+=p){
                primes[i]=false;
            }
            p++;
            while(primes[p]==false && p<=n){
                p++;
            }
        }
        vector<int>result;
        for(int i=0; i<primes.size();i++){
            if(primes[i]) result.push_back(i);
        }
        return result;
    }
};
void test1(){
    Solution s;
    cout<<s.ifPrime(7)<<endl;
    vector<int> primes = s.getPrimes(30);
    for(auto &p:primes) cout<<p<<" ";
    cout<<endl;
    primes = s.getPrimesSieveOfEratosthenes(30);
    for(auto &p:primes) cout<<p<<" ";
    cout<<endl;
}
#endif /* primes_hpp */
