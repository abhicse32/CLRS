#include "heap.h"
#include <exception>

class MaxHeap: public Heap{
    public:
        MaxHeap(vi arr):Heap(arr){}
        MaxHeap(int* arr, int n):Heap(arr, n){}
        MaxHeap(): Heap(){}
        void max_heapify(int, int);
        void build_maxheap();
        int del_at_index(int);
        // Sorts the heaps in ascending order
        void heapsort();
};

class MaxPriorityQueue: public MaxHeap{
    public:
        MaxPriorityQueue(vi arr): MaxHeap(arr){
            build_maxheap();
        }
        MaxPriorityQueue(int* arr, int n):MaxHeap(arr, n){
            build_maxheap();
        }

        MaxPriorityQueue(): MaxHeap(){}
        int get_max_key();
        void insert(int);
        int pop_max();
        void increase_key(int index, int key);
};

void MaxHeap::max_heapify(int i, int size){
    int l = left(i), r = right(i);
    int largest = i;
    if(l < size && heap[largest] < heap[l])
        largest = l;
    if(r < size && heap[largest] < heap[r])
        largest = r;
    if(largest != i){
        swap(heap[i], heap[largest]);
        max_heapify(largest, size); 
    }
}

void MaxHeap::build_maxheap(){
    for(int i = (heap.size()>>1)-1; i >=0; --i)
        max_heapify(i, heap.size()); 
}

void MaxHeap::heapsort(){
   for(int i = heap.size() - 1; i > 0; --i){
       swap(heap[i], heap[0]);
       max_heapify(0, i);
   }
}

int MaxHeap::del_at_index(int index){
    int val = INT_MIN;
    try{
        if(index >= heap.size() || index < 0)
            throw "Index out of range";
        val = heap[index];
        heap[index] = heap[heap.size() - 1];
        heap.pop_back();
        max_heapify(index, heap.size());  
    }catch(const char* err_msg){
        cout <<"Error: " <<err_msg << endl;
    } 
    return val;
}
/*
 * Max Priority Queue implementation
 * */
int MaxPriorityQueue::get_max_key(){
    try{
        return heap[0];
    }catch(exception &e){
       cout << "Invalid Operation:" << e.what() <<endl;
    }
    return INT_MIN;
}

int MaxPriorityQueue::pop_max(){
    return del_at_index(0);
}

void MaxPriorityQueue::insert(int key){
    if(heap.empty())
        heap.push_back(key);
    else{
        heap.push_back(INT_MIN);
        increase_key(heap.size() - 1, key);
    }
}

void MaxPriorityQueue::increase_key(int index, int key){
    try{
        if(index < 0 or index >= heap.size() or heap[index] >= key)
            throw "Index out of range or existing key is larger than or equal to the current key";
        heap[index] = key;
        for(int p = parent(index); p >= 0 && heap[p] < heap[index]; swap(heap[p], heap[index]),
                index = p, p = parent(p));
    }catch(const char* err_msg){
        cout << "Error: " << err_msg <<endl;
    } 
}
