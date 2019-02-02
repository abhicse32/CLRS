#include "generic_heap.h"
#include <exception>

template<class T>
class MaxHeap: public Heap<T>{
    public:
        MaxHeap(vector<T> arr): Heap<T>(arr){}
        MaxHeap(T* arr, int n): Heap<T>(arr, n){}
        MaxHeap(): Heap<T>(){}
        
        void max_heapify(int, int);
        void build_maxheap();
        void heapsort();
        T del_at_index(int);
};

template<typename T>
class MaxPriorityQueue: public MaxHeap<T>{
    public:
        MaxPriorityQueue(vector<T> arr): MaxHeap<T>(arr){
            MaxHeap<T>::build_maxheap();
        }
        MaxPriorityQueue(T* arr, int n): MaxHeap<T>(arr, n){
            MaxHeap<T>::build_maxheap();
        }
        MaxPriorityQueue(): MaxHeap<T>(){}    
        
        T get_max_key();
        void insert(T); 
        void increase_key(int, T);
        T pop_max();    
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

template<typename T>
T MaxHeap<T>::del_at_index(int index){
   try{
       vector<T>& arr = this->arr;
       int size = arr.size();
       if(index < 0 || index >= size)
           throw "Index out of range";
        T val = arr[0];
        arr[index] = arr[size - 1];
        arr.pop_back();
        max_heapify(index, size -1); 
        return val;
   }catch(const char* error){
        cout << "Exception: " << error <<endl;
   }
    return T(); 
}

// MaxPriorityQueue implementation
template<typename T>
T MaxPriorityQueue<T>::get_max_key(){
    try{
        if(this->arr.size() < 1)
            throw "operation on an empty queue";
        return this->arr[0];
    }catch(const char* err_msg){
        cout << "Error: " << err_msg << endl;
    }
}

template<typename T>
T MaxPriorityQueue<T>::pop_max(){
    return this->del_at_index(0);
}

template<typename T>
void MaxPriorityQueue<T>::increase_key(int index, T val){
    try{
        vector<T>& arr= this->arr;
        if(arr[index] >= val) 
            throw "Existing key is greater than the current key";
        for(int p = this->parent(index); index > 0 && arr[p] < val;
                index = p, p = this->parent(p))
            arr[index] = arr[p];
        arr[index] = val;
          
    }catch(const char* err_msg){
        cout << "Error: " << err_msg <<endl;
    }
}


template<typename T>
void MaxPriorityQueue<T>::insert(T val){
    this->arr.push_back(T(INT_MIN, INT_MIN));
    increase_key(this->arr.size() - 1 ,val);
}
