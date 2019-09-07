//
//  main.cpp
//  leetcode
//
//  Created by Prince Jain on 6/2/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//


#include <iostream>
#include "treeFromString.h"
int main(int argc, const char * argv[]) {
    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
    return 0;
}
//#include <vector>
//#include <string>
//#include <map>
//#include <set>

//using namespace std;
//class Solution {
//public:
//    int expressiveWords(string S, vector<string>& words) {
//
//    }
//};
//void test1(){
//    Solution s;
//
//}

//Did anyone solve the candy crush string problem ?

#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
//bool is_prime (int x) {
//    for (int i=2; i<x; ++i) if (x%i==0) return false;
//    std::cout<<"is prime"<<std::endl;
//    return true;
//}
//
//int main ()
//{
//    // call function asynchronously:
//    std::future<bool> fut = std::async (is_prime,444444443);
//
//    // do something while waiting for function to set future:
//    //    std::cout << "checking, please wait";
//    //    std::chrono::milliseconds span (100);
//    //    while (fut.wait_for(span)==std::future_status::timeout)
//    //        std::cout << '.' << std::flush;
//
//    //    bool x = fut.get();     // retrieve return value
//
//    //    std::cout << "\n444444443 " << (x?"is":"is not") << " prime.\n";
//
//    return 0;
//}
