// numword-test.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-04
#include <cstdio>
#include "numword-pj.h"
using namespace std;

int main() {
    bw::numword nw;
    uint64_t n;
    
//    n = 3; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 47; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 73; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 1492; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 10012; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 100073; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 1000000; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 1000000001; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 123000000000; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 474142398123; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 1474142398007; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 999000000000000; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 999999999999999999; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
//    n = 1000000000000000000; printf("n is %lld, ", n); std::cout<<nw.words(n)<<std::endl;
    
    n = 3; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 47; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 73; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 1492; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 10012; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 100073; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 1000000; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 1000000001; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 123000000000; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 474142398123; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 1474142398007; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 999000000000000; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 999999999999999999; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    n = 1000000000000000000; printf("n is %lld, ", n); std::cout<<nw(n)<<std::endl;
    return 0;
}

