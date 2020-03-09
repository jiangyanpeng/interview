//
// Created by Administrator on 2020/2/28.
//

#ifndef DATASTRUCT_STACK_H
#define DATASTRUCT_STACK_H

#include <iostream>
#include "List.h"

class Stack {
    public:
        Stack(int initSize) : arr(nullptr), top(0), MaxSize(initSize) {
            if (initSize < 1) {
                std::cerr << "initSize error" << std::endl;
            }
            arr = new int[initSize];
        }

        ~Stack() {
            if (arr) {
                delete[] arr;
                arr = 0;
            }
            top = 0;
        }

        Stack(const Stack &rhs);

        Stack &operator=(const Stack &rhs);

        int size() const {
            return top;
        }

        bool empty() const {
            return top == 0 ? true : false;
        }

        void push(int value);

        int pop();

        int peek() {
            if(size()) {
                return arr[top - 1];
            }
            return -1;
        }

    private:
        int *arr;//有指针，要写三大函数
        int top;
        int MaxSize;
};


class ListStack{
public:
    ListStack()= default;
    ListStack(int *arr, unsigned int size, int Max):m_p(nullptr),size(size),MaxSize(Max){
        if(Max<1){
            std::cerr<<"Max size is error"<<std::endl;
        }
        if(m_p){
            delete m_p;
            m_p= nullptr;
        }
        m_p = new ListNode;
        ListNode* p = m_p;
        for (unsigned int i = 0; i < size; ++i) {
            ListNode* temp = new ListNode;
            temp->data=arr[i];
            p->next=temp;
            p=p->next;
        }
    }
    ~ListStack(){
        if(m_p){
            delete m_p;
            m_p=0;
        }
        m_p=0;
    }

    void push(int value);

    int pop();

    int peek(){
        if(empty()){
            std::cerr<<"stack empty"<<std::endl;
        }
        ListNode* p =m_p;
        int count=0;
        while (count<size){
            p=p->next;
            count++;
        }
        return p->data;
    }

    bool empty(){
        if(size != 0){
            return false;
        }
        return true;
    }
    int Size(){
        return size;
    }

    void print(){
        ListNode* p = m_p->next;
        for (unsigned int i = 0; i < size; ++i) {
            std::cout<<p->data<<std::endl;
            p=p->next;
        }
    }
private:
    ListNode *m_p;
    unsigned int size;
    int MaxSize;
};


#endif //DATASTRUCT_STACK_H
