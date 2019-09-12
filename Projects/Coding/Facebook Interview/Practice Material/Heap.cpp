#include<iostream>
using namespace std;
class minHeap{
public:
    int *mheap;
    int capacity;
    int numElements;
    minHeap(int n){
        this->capacity = n;
        this->mheap = new int[n];
        this->numElements = 0;
    }
    void insertElement(int a){
        if(numElements+1 < capacity){
            arr[this->numElements] = a;
            int tempIndex = this->numElements;
            while(a > mheap[findParent(tempIndex)]){
                mheap[tempIndex] = mheap[findParent(tempIndex)];
                mheap[findParent(tempIndex)] = a;
                tempIndex = findParent(tempIndex);
            }
            this->numElements++;
        }
        else{
            cerr<<"Heap limit exceeded!"<<endl;
        }
    }
    int findParent(int i){
        return (i-1)/2;
    }
    int getLeftChild(int i){
        return ((2*i) + 1);
    }
    int getRightChild(int i){
        return ((2*i) + 2);
    }


    void removeMin(){

    }


};
