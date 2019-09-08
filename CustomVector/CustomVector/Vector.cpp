//
//  Vector.cpp
//  Vector
//
//  Created by Prince Jain on 9/7/19.
//  Copyright © 2019 Prince Jain. All rights reserved.
//

#include "Vector.hpp"
// constructors
template<class T> Vector<T>::Vector(){}
template<class T> Vector<T>::Vector(size_t sz,const T& val):arr(new T[sz]),capacity(sz),size(sz){
    //if(std::is_integral<T>::value == false) return;
    for(size_t i=0; i<sz; i++){
        arr[i] = (T)val;
    }
}
template<class T> Vector<T>::Vector(const Vector & cVec){
    capacity = cVec.capacity;
    size = cVec.size;
    arr = new T[capacity];
    for(size_t i=0; i<size; i++) arr[i] = cVec.arr[i];
}
template<class T> Vector<T>::Vector(Vector&& cVec){
    arr = std::move(cVec.arr);
    capacity = std::move(capacity);
    size = std::move(size);
}
template<class T> Vector<T>::~Vector(){ clear();}

template<class T>
void Vector<T>::increaseCapacity(size_t newcap){
    T * newArr = new T[newcap];
    for(size_t i=0; i<size; i++){
        newArr[i] = arr[i];
    }
    delete[]arr;
    arr = newArr;
    capacity = newcap;
}
template<class T>
void Vector<T>::reduceCapacity(size_t newcap){
    T* arrToDelete = arr + (capacity-newcap);
    delete[] arrToDelete;
}
template <class T>
void Vector<T>::checkRange(size_t i) const {
    if(i<0 || i>=size) throw std::out_of_range("out of range");
}
template <class T>
T & Vector<T>::operator[](const size_t i) const{
    checkRange(i);
    return arr[i];
}
template <class T>
Vector<T> Vector<T>::operator=(const Vector<T>& cVec){
    clear();
    arr = new T[cVec.capacity];
    size = cVec.size;
    capacity = cVec.capacity;
    for(size_t i=0; i<size; i++){ arr[i] = cVec[i];}
    return *this;
}
template <class T>
size_t Vector<T>::getSize()const{ return size;}
template <class T>
size_t Vector<T>::getCapacity()const{ return capacity;}

template <class T>
T Vector<T>::at(const size_t i) const{
    checkRange(i);
    return arr[i];
}
template <class T>
T Vector<T>::set(const size_t i, T val) const{
    checkRange(i);
    arr[i] = val;
}
template <class T>
T Vector<T>::get(const size_t i) const{
    checkRange(i);
    return arr[i];
}
template <class T>
T Vector<T>::front() const{
    checkRange(size-1);
    return arr[0];
}
template <class T>
T Vector<T>::back() const{
    checkRange(size-1);
    return arr[size-1];
}

template <class T>
void Vector<T>::push_back(const T val){
    if(size >= capacity){
        if (capacity>0) increaseCapacity(2*capacity);
        else increaseCapacity(10);
    }
    arr[size++] = val;
}
template <class T>
T Vector<T>::pop_back(){
    if(size==0) throw std::out_of_range("empty vector");
    T ret = arr[--size];
    if(size < capacity/2) reduceCapacity(capacity/2);
    return ret;
}
template <class T>
typename Vector<T>::iterator Vector<T>::begin(){
    return arr;
}
template <class T>
typename Vector<T>::iterator Vector<T>::end(){
    return arr+size;
}

template <class T>
void Vector<T>::printVec(){
    if(size==0) return;
    for(size_t i=0; i<size-1; i++){
        std::cout<<arr[i]<< ", ";
    }
    std::cout<<arr[size-1];
    std::cout<<std::endl;
}
template<class T> void Vector<T>::clear(){
    if(arr==nullptr) return;
    delete[]arr;
    capacity=0;
    size=0;
    arr = nullptr;
}
