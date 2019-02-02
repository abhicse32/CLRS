#include "StackUsingPQ.cpp"
#include <iostream>
#include <vector>
using namespace std;

class TestClass{
    private:
        int value, key;
    public:
        TestClass(int a, int b):key(a), value(b){}
        TestClass(int a, ...): key(a){}
        TestClass():key(0), value(0){}

        friend ostream& operator<< (ostream& stream, const TestClass& t){
            stream << t.key <<":" << t.value;
            return stream;
        }

        bool operator < (TestClass& t){
            return this->key < t.key;
        }

        bool operator> (TestClass& t){
            return this->key > t.key;
        }

        bool operator <= (TestClass& t){
            return key <= t.key;
        }

        bool operator >= (TestClass& t){
            return key >= t.key;
        }

        bool operator == (TestClass& t){
            return (key == t.key && value == t.value);
        }
};

int main(){
    int arr[] ={19,12,0,14,11,19,76}; 
    Stack<TestClass> stack = Stack<TestClass>();
    for(int i=0; i< sizeof(arr)/sizeof(int); ++i)
        stack.push(TestClass(i, arr[i]));
    stack.print();
    while(not stack.is_empty())
        cout << stack.pop() <<" ";

}
