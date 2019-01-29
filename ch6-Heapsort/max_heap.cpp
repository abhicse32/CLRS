#include "heap.h"
#include <exception>

class MaxHeap: public Heap{
    public:
        MaxHeap(vi arr):Heap(arr){
            build_maxheap();
        }

        MaxHeap(int* arr, int n):Heap(arr, n){
            build_maxheap();
        }

        MaxHeap(): Heap(){}
        void max_heapify(int, int);
        void build_maxheap();
        // Sorts the heaps in ascending order
        void heapsort();
};

class MaxPriorityQueue: public MaxHeap{
    public:
        MaxPriorityQueue(vi arr): MaxHeap(arr){}
        MaxPriorityQueue(int* arr, int n):MaxHeap(arr, n){}

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
    try{
        int max = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        max_heapify(0, heap.size());
        return max;
    }catch(exception& e){
        cout <<"Invlaid operation: " << e.what() << endl;
    } 
    return INT_MIN;
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
        if(index >= heap.size() or heap[index] >= key)
            throw "Index out of range or existing key is larger than or equal to the current key";
        heap[index] = key;
        for(int p = parent(index); p >= 0 && heap[p] < heap[index]; swap(heap[p], heap[index]),
                index = p, p = parent(p));
    }catch(const char* err_msg){
        cout << "Error: " << err_msg <<endl;
    } 
}
