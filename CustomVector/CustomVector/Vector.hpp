//
//  Vector.hpp
//  Vector
//
//  Created by Prince Jain on 9/7/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <iostream>

template <class T>
class Vector{
    T* arr = nullptr;
    size_t size;
    size_t capacity;
    typedef T* iterator;
    void increaseCapacity(size_t newcap);
    void reduceCapacity(size_t newcap);
    void checkRange(size_t i) const;
public:
    // constructors
    Vector();
    Vector(size_t sz, const T& val= T(0));
    Vector(const Vector<T> & cVec);
    Vector(Vector<T> && cVec);
    // destructor
    ~Vector();
    // operator
    T & operator[](const size_t i) const;
    Vector<T> operator=(const Vector<T>& cVec);
    // methods
    size_t getSize() const;
    size_t getCapacity() const;
    void clear();
    T at(const size_t i) const;
    T set(const size_t i, T val) const;
    T get(const size_t i) const;
    T front() const;
    T back() const;
    void push_back(const T val);
    T pop_back();
    typename Vector<T>::iterator begin();
    typename Vector<T>::iterator end();
    void printVec();
    template <class OT>
    friend std::ostream& operator<<(std::ostream& os, const Vector<OT>& vec);
};
template <class OT>
std::ostream& operator<<(std::ostream& os, const Vector<OT>& vec){
    if(vec.size ==0) return os;
    for(size_t i=0; i<vec.size -1; i++) os<<vec.arr[i]<<", ";
    os<<vec.arr[vec.size-1]<<std::endl;
    return os;
}
#endif /* Vector_hpp */
