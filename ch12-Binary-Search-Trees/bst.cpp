#include "bst.h"

template<typename T>
void BST<T>::inorder(Node<T>* curr_node){
    if(curr_node){
        inorder(curr_node->left);
        cout << curr_node->data <<" ";
        inorder(curr_node->right); 
    } 
}

template<class T>
void BST<T>::preorder(Node<T>* curr_node){
    if(curr_node){
        cout << curr_node->data <<" ";
        preorder(curr_node->left);
        preorder(curr_node->right);
    } 
}

template<typename T>
void BST<T>::postorder(Node<T>* curr_node){
    if(curr_node){
        postorder(curr_node->left);
        postorder(curr_node->right);
        cout << curr_node->data <<" ";
    }
}

template<class T>
Node<T>* BST<T>::insert_util(Node<T>* node, T data){
    if(!node)
        return new Node<T>(data);
    Node<T>* child;
    if(node->data < data)
        node->right = (child = insert_util(node->right, data));
    else if(node->data > data)
        node->left = (child = insert_util(node->left, data));
    child->parent = node;
    return node; 
}

template<typename T>
Node<T>* BST<T>::insert(T key){
    return insert_util(root, key);
}

template<typename T>
Node<T>* BST<T>::search_util(Node<T>* node, T key){
    if(node == nullptr or node->data == key)
        return node;
    else if(node->data < key)
       return search_util(node->right, key);
   else return search_util(node->left, key); 
}

template<class T>
Node<T>* BST<T>::search(T key){
    return search_util(root, key);
}

template<class T>
Node<T>* BST<T>::tree_minimum(Node<T>* node){
    if(node){
        while(node->left) node = node->left;
        return node;
    }
    return nullptr;
}

template<class T>
Node<T>* BST<T>::tree_maximum(Node<T>* node){
    if(node){
        while(node->right) node = node->right;
        return node;
    }
    return nullptr;
}

template<typename T>
Node<T>* BST<T>::predecessor(Node<T>* node){
    if(node->left)
        return tree_maximum(node->left);
    else{
        Node<T>* p = node->parent;
        while(p && p->left == node)
           node = p, p = p->parent;
        return p; 
    }
}

template<typename T>
Node<T>* BST<T>::successor(Node<T>* node){
    if(node->right) 
        return tree_minimum(node->right);
    else{
        Node<T>* p = node->parent;
        while(p and p->right == node)
            node = p, p = p->parent;
        return p;
    }
}

template<typename T>
void BST<T>::delete_node(T key){
}
