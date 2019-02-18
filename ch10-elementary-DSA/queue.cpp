#include <iostream>
#include <list>

using namespace std;

template<typename T>
class Queue{
    list<T> arr;
    public:
        inline void enqueue(T val){arr.push_back(val);}
        T dequeue();
        T front();
        inline int size(){return arr.size();}
        inline bool is_empty(){return arr.empty();}
};

template<typename T>
T Queue<T>::front(){
    T ret_val = T();
    try{
        if(arr.empty()) throw string("Empty queue");
        ret_val = arr.front();
    }catch(string& err_str){
        cout << "Error: " << err_str <<endl;
    }
    return ret_val;
}

template<class T>
T Queue<T>::dequeue(){
    T ret_val = T();
    try{
        if(arr.empty()) throw string("Empty queue");
        ret_val = arr.front();
        arr.pop_front(); 
    }catch(string& err_str){
        cout <<"Error: " << err_str <<endl;
    }
    return ret_val;
}
