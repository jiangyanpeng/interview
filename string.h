//
// Created by Administrator on 2020/2/29.
//

#ifndef DATASTRUCT_STRING_H
#define DATASTRUCT_STRING_H


#include <cstring>

class string {
public:
    string()= default;
    string(char *nums,int size,int MaxSize_): arr(nullptr), Size(MaxSize_){
        if(nums==0){
            arr = new char[1];
            *arr='\0';
        }
        arr = new char[Size + 1];
        for (unsigned int i = 0; i < size; ++i) {
            arr[i] = nums[i];
        }
        arr[size+1]='\0';
    }
    string(const char* ptr=" "): arr(nullptr), Size(strlen(ptr)){
        if(ptr== nullptr){
            arr=new char[1];
            *arr='\0';
        }
        arr=new char[strlen(ptr)+1];
        strcpy(arr,ptr);
    }
    string(const string& rhs): arr(new char[strlen(rhs.arr)+1]), Size(rhs.Size){
        strcpy(arr,rhs.arr);
    }
    string& operator = (const string& rhs){
        if(this != &rhs){
            arr = new char[strlen(rhs.arr)+1];
            strcpy(arr,rhs.arr);
            return *this;
        }
    }

    int size()const {
        return Size;
    }

    bool empty() const ;

    //string& operator + (const string& rhs);

    //char& operator [](const string& rhs);

    void print()const ;
private:
    char* arr;///类成员为指针，注意big three（深copy与浅copy）
    int Size;
};


#endif //DATASTRUCT_STRING_H
