//
// Created by Administrator on 2020/2/28.
//

#include "Stack.h"
Stack::Stack(const Stack &rhs): arr(new int[rhs.MaxSize]), top(rhs.top), MaxSize(rhs.MaxSize) {
    for (int i = 0; i < top; ++i) {
        arr[i]=rhs.arr[i];
    }
}
Stack &Stack::operator=(const Stack &rhs) {
    arr=new int[rhs.MaxSize];
    for (int i = 0; i < top; ++i) {
        arr[i]=rhs.arr[i];
    }
    return *this;
}
void Stack::push(int value) {
    if(top==MaxSize){
        std::cerr<<"stack full"<<std::endl;
        return;
    }
    arr[top++]=value;
}
int Stack::pop() {
    if(top==0){
        std::cerr<<"stack empty"<<std::endl;
    }
    return arr[--top];
}
void ListStack::push(int value) {
    if(size==MaxSize){
        std::cerr<<"stack full"<<std::endl;
        return;
    }
    ListNode* temp = new ListNode;
    temp->data=value;
    ListNode* p = m_p;
    int count=0;
    while (count<size){
        p=p->next;
        count++;
    }
    p->next=temp;
    size++;
}
int ListStack::pop() {
    if(empty()){
        std::cerr<<"stack empty"<<std::endl;
    }
    int count=0;
    ListNode* p = m_p;
    while (count<size){
        p=p->next;
        count++;
    }
    size--;
    int result = p->data;
    delete p;
    return result;
}