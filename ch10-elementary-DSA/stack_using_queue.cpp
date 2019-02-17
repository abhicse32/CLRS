#include "queue.cpp"

template<typename T>
class Stack{
    private:
        Queue<T> queue, aux_queue;
    public:
        Stack(){}
        void push(T val);
        int size(){return queue.size();}
        bool is_empty(){return queue.is_empty();}
        T pop();
        T top();
};

template<typename T>
void Stack<T>::push(T val){
    while(!queue.is_empty()) 
        aux_queue.enqueue(queue.dequeue());
    queue.enqueue(val);
    while(!aux_queue.is_empty())
        queue.enqueue(aux_queue.dequeue());
}

template<class T>
T Stack<T>::pop(){
    return queue.dequeue();
}

template<typename T>
T Stack<T>::top(){
    T ret_val = T();
    try{
        if(queue.is_empty())
            throw string("Invalid operation on empty queue");
        ret_val = queue.front();
    }catch(string& err_str){
        cout << "Error: " << err_str <<endl;
    }
    return ret_val;
}
