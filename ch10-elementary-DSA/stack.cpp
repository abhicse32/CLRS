#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Stack{
    vector<T> arr;
    public:
        inline void push(T val){arr.push_back(val);} 
        T pop();
        inline int size(){return arr.size();}
        bool is_empty(){return arr.empty();}
        T top();
};

template<typename T>
T Stack<T>::top(){
    T val = T();
    try{
        if(arr.empty())
            throw string("Empty stack");
        val = arr.back();
    }catch(string& err_str){
        cout <<"Error: " << err_str <<endl;
    }
    return val;
}

template<typename T>
T Stack<T>::pop(){
    T val = T();
    try{
        if(arr.empty())
            throw string("Empty stack");
        val = arr.back();
        arr.pop_back(); 
    }catch(string& err_str){
        cout <<"Error: " << err_str <<endl;
    }
    return val;
}
