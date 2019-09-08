//
//  main.cpp
//  Vector
//
//  Created by Prince Jain on 9/7/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#include <iostream>
#include "Vector.hpp"
#include "Vector.cpp"
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "custom vector!\n";
    Vector<int> cv(5,6);
    cv[1]=10;
    std::cout<<cv;
    Vector<int> cv2(cv);
    cv.pop_back();
    std::cout<<cv;
    std::cout<<cv2;
    cv2 = cv;
    std::cout<<cv2;
    Vector<Vector<int>> vecvec(5,Vector<int>(4,5));
    std::cout<<vecvec;
    std::cout<<vecvec[0][0]<<std::endl;
    for(auto &i:vecvec) std::cout<<i<<", ";
 //   vecvec[0].push_back(10);
    return 0;
}
