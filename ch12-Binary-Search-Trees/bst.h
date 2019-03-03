#include <iostream>
using namespace std;

template<typename T> class BST;
template<typename T>
class Node{
    private:
        T data;
        Node* left, *right;
        Node* parent;
        friend class BST<T>;
    public:
        Node(T key): data(key){
            left = right = nullptr;
            parent = nullptr;
        }
        inline T get_data(){return data;} 
};

template<typename T>
class BST{
    friend Node<T>;
    Node<T>* root;
    public:
        BST(){
            root = nullptr;
        }
        inline Node<T>* get_root(){return root;}
        inline void set_root(Node<T>* node){root = node;}
        void inorder(Node<T>*);
        void preorder(Node<T>*);
        void postorder(Node<T>*);
        Node<T>* search(T);
        Node<T>* search_util(Node<T>*, T);
        void delete_node(T);
        Node<T>* insert(T);
        Node<T>* insert_util(Node<T>*, T);
        Node<T>* tree_maximum(Node<T>*);
        Node<T>* tree_minimum(Node<T>*);
        Node<T>* predecessor(Node<T>*);
        Node<T>* successor(Node<T>*);
};
