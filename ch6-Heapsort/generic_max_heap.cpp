#include "generic_heap.h"

template<class T>
class MaxHeap: public Heap<T>{
    public:
        MaxHeap(vector<T> arr): Heap<T>(arr){}
        MaxHeap(T* arr, int n): Heap<T>(arr, n){}
        MaxHeap(): Heap<T>(){}
        
        void max_heapify(int, int);
        void build_maxheap();
        void heapsort();
};

template<class T>
void MaxHeap<T>::max_heapify(int index, int size){
    int l = Heap<T>::left(index), r = Heap<T>::right(index);
    /*Can also use this->left() and this->right() instead of the above*/
    vector<T>& arr = this->arr;
    int largest = index;
    if(l < size && arr[largest] < arr[l])
        largest = l;
    if(r < size && arr[largest] < arr[r])
        largest  = r;
    if(largest != index){
        swap(arr[largest], arr[index]);
        max_heapify(largest, size);
    } 
}

template<typename T>
void MaxHeap<T>::build_maxheap(){
    int size = this->arr.size();
    for(int i=(size >> 1)-1; i >= 0; --i)
        max_heapify(i, size);
}

template<typename T>
void MaxHeap<T>::heapsort(){
    vector<T>& arr= this->arr;
    int size = arr.size();
    for(int i = size - 1; i > 0 ; --i){
        swap(arr[i], arr[0]);
        max_heapify(0, i); 
    }
}



