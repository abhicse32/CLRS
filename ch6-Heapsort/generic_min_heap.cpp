#include "generic_heap.h"

template<class T>
class MinHeap: public Heap<T>{
    protected:
        using Heap<T>::arr;
        using Heap<T>::left;
        using Heap<T>::right;
        using Heap<T>::parent;

    public:
        MinHeap(vector<T> arr): Heap<T>(arr){}
        MinHeap(T* arr, int n): Heap<T>(arr, n){}
        MinHeap(): Heap<T>(){}
        
        void min_heapify(int, int);
        void build_minheap();
        void heapsort();
        T del_at_index(int);
};

template<typename T>
class MinPriorityQueue: public MinHeap<T>{
    using MinHeap<T>::parent;

    public:
        MinPriorityQueue(vector<T> arr): MinHeap<T>(arr){
            this->build_minheap();
        }
        MinPriorityQueue(T* arr, int n): MinHeap<T>(arr, n){
            this->build_minheap();
        }    
        MinPriorityQueue(): MinHeap<T>(){}
        
        T pop_min();
        void decrease_key(int, T);
        void insert(T);
        T get_min();     
};


template<class T>
void MinHeap<T>::min_heapify(int index, int size){
    int l = left(index), r = right(index);
    int smallest_ind = index;
    if(l < size && arr[l] < arr[smallest_ind])
        smallest_ind = l;
    if(r < size && arr[r] < arr[smallest_ind])
        smallest_ind = r;
    if(smallest_ind != index){
        swap(arr[index], arr[smallest_ind]);
        min_heapify(smallest_ind, size);
    }   
}

template<typename T>
void MinHeap<T>::build_minheap(){
    for(int i = (arr.size()>>1) - 1; i >= 0 ; --i)
       min_heapify(i, arr.size()); 
}

template<class T>
void MinHeap<T>::heapsort(){
    for(int i= arr.size() - 1; i > 0; --i){
        swap(arr[0], arr[i]);
        min_heapify(0, i);
    }
}

template<class T>
T MinHeap<T>::del_at_index(int index){
    T val = T();
    try{        
        if(index < 0 || index >= arr.size())
            throw string("Index out of range");
        val = arr[index];
        arr[index] = arr[arr.size() - 1];
        arr.pop_back();
        min_heapify(index, arr.size());
    }catch(string& err_str){
        cout <<"Error: " <<err_str <<endl;
    }
    return val;
}

// MinPriorityQueue implementation

template<typename T>
T MinPriorityQueue<T>::pop_min(){
    return MinHeap<T>::del_at_index(0);
}

template<typename T>
T MinPriorityQueue<T>::get_min(){
    T val = T();
    try{
        if(this->arr.size() < 1)
            throw string("Empty queue");
        val = this->arr[0];
    }catch(string& str) {
        cout << "Error: " << str <<endl;
    }
    return val;
}

template<class T>
void MinPriorityQueue<T>::decrease_key(int index, T val){
    try{
        vector<T>& arr  = MinHeap<T>::arr;
        if(val >= arr[index])
            throw string("Existing object is smaller"); 
        for(int p = parent(index); index > 0 && val < arr[p]; index = p, p = parent(p))
            arr[index] = arr[p];
        arr[index] = val;

    }catch(string& err_str){
        cout << "Error: " <<err_str << endl;
    } 
}       

template<typename T>
void MinPriorityQueue<T>::insert(T val){
    this->arr.push_back(T(INT_MAX));
    decrease_key(this->arr.size() - 1, val);
}
