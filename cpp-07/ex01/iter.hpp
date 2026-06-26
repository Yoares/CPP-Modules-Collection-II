#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <vector>
template <typename T> 
void iter(T*  arr, const  size_t size, void (*func)(T &)){
    for(size_t i = 0; i < size; i++ ){
       func(arr[i]);
    }
}
template <typename T>
void print(T& val){
    std::cout << val << std::endl;
}
#endif