//
// Created by Administrator on 2020/2/27.
//
#include <iostream>
#include "List.h"

bool List::InitList(int array[], unsigned int size) {
    if(!head){
        head=new ListNode;
    }
    ListNode* temp=head;
    for (unsigned int i = 0; i < size; ++i) {
        ListNode* p=new ListNode;
        p->data=array[i];
        temp->next=p;
        temp=temp->next;
    }
    return true;
}
bool List::insert(unsigned int position, int value) {
    if(!head && position< 1 && position>size()+1){
        std::cerr<<"error"<<std::endl;
        return false;
    }

    ListNode*p =head;
    ListNode* q=new ListNode;
    while (position-1){
        p=p->next;
        position--;
    }
    q->data=value;
    q->next=p->next;
    p->next=q;
    return true;
}
ListNode * List::GetNode(ListNode *head, unsigned int position)  {
    if(!head && position>size()+1){
        std::cerr<<"out of range"<<std::endl;
        return head;
    }
    if(position == 0){
        return head;
    }
    ListNode *p=head->next;
    for (unsigned int i = 1; i != position; ++i) {
        p=p->next;
    }
    return p;
}
void List::print() const {
    ListNode *p=head->next;
    while (p){
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}
bool List::Delete(unsigned int position) {
    if(!head && position<1 && position>size()){
        return false;
    }
    ListNode* p=GetNode(head,position-1);
    p->next=p->next->next;
    return true;
}
void List::clear() {
    ///怎么才能逐个删除！！
    delete head;
}