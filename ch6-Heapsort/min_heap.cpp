#include "heap.h"
#include <exception>

class MinHeap: public Heap{
    public:
        MinHeap(vi arr):Heap(arr){
            build_minheap();
        }
        MinHeap(int* arr, int n):Heap(arr, n){
            build_minheap();
        }

        MinHeap():Heap(){}
        void min_heapify(int, int);
        void build_minheap();
        // this will sort the array/heap in descending order
        void heapsort();
};

class MinPriorityQueue: public MinHeap{
    public:
        MinPriorityQueue(vi arr): MinHeap(arr){}
        MinPriorityQueue(int* arr, int n): MinHeap(arr, n){}
        void insert(int );
        int get_minimum();
        int pop_min();
        void decrease_key(int, int);     
};



void MinHeap::min_heapify(int i, int size){
    int l = left(i), r = right(i); 
    int smallest = i;
    if(l < size && heap[l] < heap[smallest])
        smallest = l;
    if(r < size && heap[r] < heap[smallest])
        smallest = r;
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        min_heapify(smallest, size);
    }
}

void MinHeap::build_minheap(){
    int size = heap.size();
    for(int i = (size>>1)-1; i>=0; --i)
        min_heapify(i, size);
}

void MinHeap::heapsort(){
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[i], heap[0]);
        min_heapify(0, i);
    }
}


/*
 * Min Priority Queue implementation
 * */

int MinPriorityQueue::get_minimum(){
    try{
        if(heap.size() < 1)
            throw "Queue has no elements";
        return heap[0];
    }catch(const char* e){
        cout << "Exception: " << e <<endl;
    }
    return INT_MAX;
}

int MinPriorityQueue::pop_min(){
   try{
       if(heap.size() < 1)
           throw "Can't pop an element from an empty queue";
       int min = heap[0];
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        min_heapify(0, heap.size());
        return min;
   }catch(const char* error_msg){
        cout << "Error: " << error_msg << endl;
   }
   return INT_MAX;
}

void MinPriorityQueue::decrease_key(int index, int key){
    try{
        if(index >= heap.size() or heap[index] <= key)
            throw "Invalid operation";
        heap[index] = key;
        for(int p = parent(index); index > 0 && heap[p] > heap[index]; swap(heap[index], heap[p]), index = p, p = parent(p));
    }catch(const char* err_str){
        cout << err_str <<endl;
    }
}

void MinPriorityQueue::insert(int key){
    heap.push_back(INT_MAX);
    decrease_key(heap.size()-1, key); 
}
