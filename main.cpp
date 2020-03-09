//#include "List.h"
#include <iostream>
#include <chrono>
#include <stdint.h>
#include "Stack.h"
#include "string.h"
#include <vector>

using namespace std;

///Leetcode 2 two summary (2 -> 4 -> 3) + (5 -> 6 -> 4) = 7 -> 0 -> 8
ListNode* reverseList(ListNode* head);

void bulusort(int arr[],int size);
void selete_sort(int arr[], int length);
void selete2(int arr[], unsigned int length);
void insert_sort(int arr[], unsigned int size);
void swap(int arr[],int a, int b);
int FindMax(int arr[], unsigned int left , unsigned int right);

void merge_sort(int arr[], unsigned int left, unsigned int right);
void sort(int arr[], unsigned int left, unsigned int right);
void merge(int arr[], unsigned int left, unsigned int mid, unsigned int right);

int partition(int arr[],int left,int right);
int part(int arr[], int left, int right);
int*partition_flag(int arr[], int left, int right);

void heapInsert(int arr[],int index);
void heapify(int arr[],int index, int heapSize);
void heapSort(int arr[], int size);
//有bug
void rotateEdge(vector<vector<int> >&m,int a, int b,int c,int d);
void rotate(vector<vector<int>>&m);
void printEdge();

bool palindromic(ListNode*head);
int main(){
    int array[38]={100,6,22,34,78,10,0,99,100,45,567,78,45,67,88,99,0,23,45,67,77,88,44,24,4,5,6,7,223,56,86,43,87,25,6,7,78,89};
    auto start = std::chrono::steady_clock::now();
    bulusort(array,38);
    //selete_sort(array,38);
    //selete2(array,38);
    //insert_sort(array,38);
    //merge_sort(array,0,37);
    //int result = part(array,0,37);
    //int * result=partition_flag(array,0,37);
    //heapSort(array,38);
//    for (int i = 0; i < 38; ++i) {
//        std::cout<<array[i]<<" ";
//    }
    std::cout<<std::endl;
//    vector<vector<int>>m;
//    m.push_back(vector<int>{1,2,3,4});
//    m.push_back(vector<int>{5,6,7,8});
//    m.push_back(vector<int>{9,10,11,12});
//    m.push_back(vector<int>{13,14,15,16});
//    for (int i = 0; i < m.size(); ++i) {
//        for (int j = 0; j < m[0].size(); ++j) {
//            std::cout<<m[i][j]<<"  ";
//        }
//        std::cout<<std::endl;
//    }
    //std::cout<<result[0]<<" "<<result[1]<<std::endl;
    //delete [] result;
    //std::cout<<"Max:"<<FindMax(array,0,6);
    int num[5]={1,2,3,4,5};
    List* l1= new List;
    l1->InitList(num,5);
    l1->print();
    //std::cout<<l1.GetHead()<<std::endl;
    std::cout<<palindromic(l1->GetHead()->next)<<endl;
//    std::cerr<<l1.GetHead()<<"  "<<std::endl;
//    ListNode* result = reverseList(l1.GetHead());
//    while (result){
//        std::cout<<result->data<<std::endl;
//        result = result->next;
//    }
    ///***************************///
//    Stack stack(4);
//    stack.size();
//    stack.empty();
//    stack.push(5);
//    stack.push(0);
//    stack.push(9);
//    ///*********************///
//
//    ListStack stack1(array,3,10);
//    stack1.push(4);
//    stack1.push(19);
//    std::cout<<stack1.pop()<<std::endl;
//    stack1.print();
//    ///*******************///
//    string string1("hello world");
//    std::cerr<<string1.size()<<std::endl;
//    string1.print();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double ,std::micro>time=end-start;
    std::cout<<"time: "<<time.count()<<" us"<<std::endl;
    return 0;
}
void bulusort(int arr[],int size){
    if(!arr || size==1) return;
    for (int i = size-1; i > 0 ; --i) {
        for (int j = 0; j < i; ++j) {
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}

void selete_sort(int arr[], int length){
    if(!arr || length ==1) return;
    for (int i = 0; i < length; ++i) {
        for (int j = i+1; j < length; ++j) {
            if(arr[i]>arr[j])
                swap(arr,i,j);
        }
    }
}
void selete2(int arr[], unsigned int length){
    if(!arr||length==1) return;
    for (int i = 0; i < length; ++i) {
        int index = i;
        for (int j = i+1; j < length; ++j) {
            index = arr[j]<arr[index]?j:index;
        }
        swap(arr,i,index);
    }
}
void insert_sort(int arr[], unsigned int size){
    if(!arr||size==1) return;
    for (int i = 0; i < size; ++i) {
        for (int j = i-1;j>=0&&arr[j]>arr[j+1] ;--j) {
            swap(arr,j,j+1);
        }
    }
}
void swap(int arr[],int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
ListNode* reverseList(ListNode* head){
    if(!head) return nullptr;
    ListNode* pre = nullptr;
    ListNode* cur =head;
    while (cur){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}
int FindMax(int arr[], unsigned int left, unsigned int right){

    if(left==right){
        return arr[left];
    }
    int mid = left+(right-left)/2;
    int MaxLeft = FindMax(arr,left,mid);//为什么这里是mid而是下面是mid+1？别的确实错误的？
    int MaxRight = FindMax(arr,mid+1,right);
    return MaxLeft>=MaxRight?MaxLeft:MaxRight;
}
void merge_sort(int arr[], unsigned int left, unsigned int right){
    if(!arr||(right-left)==1) return;
    sort(arr,left,right);
}
void sort(int arr[], unsigned int left, unsigned int right){
    if(left==right)
        return;
    int mid = left+(right-left)/2;
    sort(arr,left,mid);
    sort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
void merge(int arr[], unsigned int left, unsigned int mid, unsigned int right){
    int temp[right-left+1];
    int i=0;
    int p1=left,p2=mid+1;
    while(p1<=mid && p2<=right){
        temp[i++]=arr[p1]<=arr[p2]?arr[p1++]:arr[p2++];
        //std::cout<<temp[i]<<std::endl;
    }
    while(p1<=mid){
        temp[i++] = arr[p1++];
    }
    while(p2<=right){
        temp[i++] = arr[p2++];
    }
    for (int k = 0; k < right-left+1; ++k) {
        std::cerr<<temp[k]<<"  ";
    }
    std::cerr<<std::endl;
    for (int j = left; j <= right; ++j) {
        arr[j] = temp[j];
    }
}
//单线扫描
int partition(int arr[],int left,int right){
    if(!arr) return -1;
    int base = arr[0];
    int L=left-1;
    int p=left;
    while(p<=right){
        if(arr[p]<=base){
            swap(arr,++L,p++);
        }
        else{
            p++;
        }
    }
    swap(arr,left,L);
    return L;
}
int part(int arr[], int left, int right){
    if(!arr) return -1;
    int base = arr[left];
    int i = left, j = right;
    while (i<j){
        while (i<j && arr[j]>base)
            j--;
        while (i<j && arr[i]<=base)
            i++;
        swap(arr,i,j);
    }
    swap(arr,left,i);
    return  i;
}
int* partition_flag(int arr[], int left, int right){
    if (!arr) return nullptr ;
    int less = left-1,more = right+1;
    int base = arr[left];
    std::cerr<<"base "<< base<<std::endl;
    int i = left;
    while (i<more){
        if(arr[i]<base){
            swap(arr,++less,i++);
        }
        else if (arr[i]>base){
            swap(arr,--more,i);
        }
        else{
            i++;
        }
    }
    return new int[2]{++less,--more};
}

void heapInsert(int arr[],int index){
    while (arr[index] > arr[(index-1)/2]){
        swap(arr,index,(index-1)/2);
        index = (index-1)/2;
    }
}

void heapify(int arr[],int index, int heapSize){
    int left = index*2 +1;//为什么是左孩子？不是开始右孩子？
    while (left<heapSize){
        int lagest = left+1<heapSize && arr[left+1]>arr[left]?left+1:left;
        lagest = arr[lagest]>arr[index]?lagest:index;
        if(lagest==index) break;
        swap(arr,lagest,index);
        index=lagest;
        left=index*2+1;
    }
}
void heapSort(int arr[], int size){
    if(!arr||size<2) return;
    for (int i = 0; i < size; ++i) {
        heapInsert(arr,i);
    }
    int heapSize = size;
    swap(arr,0,--heapSize);//此步骤可以省略
    while(heapSize>0){
        heapify(arr,0,heapSize);
        swap(arr,0,--heapSize);
    }
}

void rotateEdge(vector<vector<int> >&m,int a, int b,int c,int d){
    int times = d-b;
    int temp=0;
    for (int i = 0; i!=times; i++) {
        temp = m[a][b+i];
        m[a][b+i]=m[c-i][b];
        m[c-i][b]=m[c][d-i];
        m[c][d-i]=m[a+i][d];
        m[a+i][d]=temp;
    }
}
void rotate(vector<vector<int>>&m){
    if(m.size()==0||m[0].size()==0||m.size()!=m[0].size())
        return;
    cerr<<"test"<<endl;
    int a=0,b=0,c=m.size()-1,d=m[0].size()-1;
    while (a<=c){
        rotateEdge(m,a++,b++,c++,d++);
    }
}
bool palindromic(ListNode*head){
    if(!head) return false;
    ListNode* slow =head;
    ListNode* fast = head->next;
    while(fast->next && fast){
      slow = slow->next;
      fast = fast->next->next;
    }
    std::cerr<<"slow:"<<slow->data;
    ListNode* pre = nullptr;
    ListNode* cur =slow;
    ListNode* temp ;
    while(cur->next){
        temp=cur->next;
        cur->next=pre;
        pre=cur;
        cur=temp;
    }
    while (head!= nullptr && cur!= nullptr){
        if(head->data != cur->data)
            return -1;
    }
    return true;
}