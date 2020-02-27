#include "List.h"
#include <iostream>
int main(){
    List list;
    int array[6]={4,1,3,8,9,5};
    list.InitList(array,6);
    list.print();
    list.insert(7,10);
    list.print();
    list.Delete(1);
    list.print();
    list.clear();
    return 0;
}