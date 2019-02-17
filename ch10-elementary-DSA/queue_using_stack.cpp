#include "stack.cpp"

template<typename T>
class Queue{
    private:
        Stack<T> queue, aux_queue;
    public:
        Queue(){}
        void enqueue(T val);
        int size(){return queue.size();}
        T dequeue();
        bool is_empty(){return queue.is_empty();} 
        T front();
};

template<class T>
void Queue<T>::enqueue(T val){
    while(!queue.is_empty())
        aux_queue.push(queue.pop());
    queue.push(val);
    while(!aux_queue.is_empty())
        queue.push(aux_queue.pop());
}

template<class T>
T Queue<T>::dequeue(){
    return queue.pop();
}

template<typename T>
T Queue<T>::front(){
    T ret_val = T();
    try{
        if(queue.is_empty())
            throw string("invalid operation on empty queue");
        ret_val = queue.top();
    }catch(string& err_str){
        cout << err_str <<endl;
    }
    return ret_val;
}
