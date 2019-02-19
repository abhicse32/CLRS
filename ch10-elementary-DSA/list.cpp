#include <iostream>
#include <exception>
#include <vector>
#include <typeinfo>
#include <stdexcept>
using namespace std;

template<class T>
class LinkedList{
    class Node{
        public:
            T data;
            Node *next, *prev;
            Node(){}
            Node(T val):data(val){
                next = prev = nullptr;
            }
    };
    
    Node *head;
    Node* last;    // maintained to perform append operation in O(1) time
    int _size;
    public:
        LinkedList(){
            head = last = nullptr;
            _size = 0;
        }

        void append(T val);
        void prepend(T val);
        void insert_at(int, T);
        inline int size(){return _size;}
        inline bool empty(){return head == nullptr;}
        T remove_at(int);
        T remove_first();
        T remove_last();
        void print();
        bool search(T);
};

template<class T>
void LinkedList<T>::append(T val){
    Node* new_node = new Node(val);
    if(last){
        last -> next = new_node;
        new_node -> prev = last;
    }else
        head = new_node;
    last = new_node;
    ++_size;
}

template<typename T>
void LinkedList<T>::prepend(T val){
    Node* new_node = new Node(val);
    if(head)
        head -> prev = new_node;
    else last = new_node;
    new_node -> next = head;
    head = new_node;
    ++_size;
}

template<typename T>
void LinkedList<T>::insert_at(int index, T val){
    try{
        if(index >= _size || index < 0)
            throw string("Index out of range");
        if(index == 0)
            prepend(val);
        else{
            Node* tmp = head;
            Node* new_node = new Node(val);
            while(--index)
                tmp = tmp -> next;
            new_node -> next = tmp -> next;
            tmp -> next = new_node;
            new_node -> prev = tmp;
        }        
    }catch(string& err_str){
        cout <<"Error: " << err_str <<endl;
    }
}

template<class T>
T LinkedList<T>::remove_first(){
    T ret_val = T();
    try{
        if(not head)
            throw string("Invalid operation on an empty list");
        Node* tmp = head;
        head = tmp -> next;
        if(head)
            head -> prev = nullptr;
        else last = head;
        ret_val = tmp -> data;
        delete tmp;
    }catch(string& err_str){
        cout << "Error: " << err_str <<endl;
    }
    return ret_val; 
}

template<typename T>
T LinkedList<T>::remove_last(){
    T ret_val = T();
    try{
        if(not last)
            throw string("Invalid operation on empty list");
        Node* tmp = last;
        last = last -> prev;
        tmp -> prev = nullptr;
        if(last)
            last -> next = nullptr;
        else head = last;
        ret_val = tmp -> data;
        delete tmp;
    }catch(string& err_str){
        cout << "Error: " << err_str <<endl;
    }
    return ret_val;
}

template<typename T>
T LinkedList<T>::remove_at(int index){
    T ret_val = T();
    try{
        if(index < 0 || index >= _size)
            throw string("Index out of range");
        if(index == 0)
            ret_val = remove_first();
        else if(index == _size - 1)
            ret_val = remove_last();
        else{
            Node* tmp = head;
            while(--index)
                tmp = tmp -> next;
            Node* del_node = tmp-> next;
            tmp -> next = del_node-> next;
            del_node-> next -> prev = tmp;
            ret_val = del_node -> data;
            delete del_node;
        }
    }catch(string& err_str){
        cout << "Exception: " << err_str <<endl;  
    }
    return ret_val;
}

template<typename T>
bool LinkedList<T>::search(T val){
    Node* tmp = head;
    while(tmp && tmp-> data != val)
        tmp = tmp -> next;
    return tmp != nullptr;
}

template<typename T>
void LinkedList<T>::print(){
    Node* tmp = head;
    while(tmp){
        cout << tmp->data <<" ";
        tmp = tmp -> next;
    }
    cout << endl;
}

