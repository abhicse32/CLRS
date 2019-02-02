#include "generic_min_heap.cpp"

template<class T>
class Queue: public MinPriorityQueue<T>{
    public:
        Queue(): MinPriorityQueue<T>(){}
        
        inline void enqueue(T val){this->insert(val);}
        inline T dequeue(){return this->pop_min();}
        inline bool is_empty(){return this->arr.size() == 0;}
        inline int size(){return this->arr.size();}
};

