#include "generic_max_heap.cpp"

template<typename T>
class Stack: public MaxPriorityQueue<T>{
    public:
        Stack(): MaxPriorityQueue<T>(){}
        
        inline void push(T val){this->insert(val);}
        inline T pop(){return this->pop_max();}
        inline int size(){return this->arr.size();}
        inline bool is_empty(){return this->arr.size() == 0;}
};
