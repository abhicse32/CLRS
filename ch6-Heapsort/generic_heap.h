#include <iostream>
#include <vector>

using namespace std;
#ifndef G_HEAP
#define G_HEAP

template<class T>
class Heap{
    protected:
        vector<T> arr;
        Heap(vector<T> arr){
            this->arr.assign(arr.begin(), arr.end());
        }   

        Heap(T* arr, int n){
            this->arr.assign(arr, arr+n);
        }

        Heap(){}

        int parent(int i){return (i-1)>>1;}
        int left(int i){return (i<<1)+1;}
        int right(int i){return (i<<1)+2;}

    public:
        inline void print(){
            for(auto& element: arr)
                cout << element <<" ";
            cout <<endl;
        }
};

#endif
