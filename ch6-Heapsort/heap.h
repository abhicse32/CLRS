#include <iostream>
#include <vector>
#define vi vector<int>
using namespace std;

#ifndef HEAP
#define HEAP
class Heap{
    public:
        inline void print(){
            for(auto& element: heap)
                cout << element <<" ";
            cout <<endl;
        }
        inline int size(){ return heap.size(); }
    protected:
        vi heap;
        Heap(vi arr){
            heap.assign(arr.begin(), arr.end());
        }

        Heap(int *arr, int n){
            heap.assign(arr, arr+n);
        }
        Heap(){}
        int parent(int i){return (i-1)>>1;}
        int left(int i){return (i<<1)+1;}
        int right(int i){return (i<<1)+2;}
};

#endif
