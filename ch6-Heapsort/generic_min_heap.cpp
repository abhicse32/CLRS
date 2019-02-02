#include "generic_heap.h"

template<class T>
class MinHeap: public Heap<T>{
    public:
        MinHeap(vector<T> arr): Heap<T>(arr){}
        MinHeap(T* arr, int n): Heap<T>(arr, n){}
        MinHeap(): Heap(){}

}

template<typename T>
class MinPriorityQueue: public heap<T>{
    public:
        MinPriorityQueue(vector<T> arr): Heap<T>(arr){}
        MinPriorityQueue(T* arr, int n): Heap<T>(arr, n);        
}
