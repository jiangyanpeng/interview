//
// Created by Administrator on 2020/2/27.
//

#ifndef DATASTRUCT_LIST_H
#define DATASTRUCT_LIST_H

#include <iostream>
struct ListNode{
    ListNode():next(nullptr){}
    int data;
    ListNode* next;
};

class List {
public:
    List(){
       if(head){
           delete head;
           head=new ListNode;
       }
       head=new ListNode;
       head->next= nullptr;
       std::cerr<<"successful  "<<head<<"  "<<head->next<<std::endl;
    }
//    ~List(){
//        clear(head);
//    }

    bool InitList(int array[], unsigned int size);

    unsigned int Length(ListNode *head){
        if(head== nullptr){
            return 0;
        }
        int count=0;
        ListNode *p = head;
        while(p){
            p=p->next;
            count++;
        }
        return count;
    }
    ListNode* GetNode(ListNode* head, unsigned int position) ;

    void print()const ;

    bool insert(unsigned int position, int value);

    bool Delete(unsigned int position);

    void clear();

    ListNode* GetHead()const {
        return head;
    }
    unsigned int size(){
        if(!head){
            return 0;
        }
        ListNode* p= head->next;
        int count = 0;
        while (p){
            p = p->next;
            count++;
        }
        return count;
    }

private:
    ListNode* head;
};


#endif //DATASTRUCT_LIST_H
