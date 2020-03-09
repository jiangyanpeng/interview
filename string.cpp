//
// Created by Administrator on 2020/2/29.
//
#include <iostream>
#include "string.h"
bool string::empty() const {
    if(Size==0){
        return false;
    }
    return true;
}
void string::print() const {
    if(arr== nullptr){
        std::cerr<<"string empty"<<std::endl;
        return;
    }
    for (unsigned int i = 0; i < Size; ++i) {
        std::cerr<<arr[i]<<std::endl;
    }
}