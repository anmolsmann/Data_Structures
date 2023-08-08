#include <iostream>
using namespace std;
template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class Stack{
    Node<T> *head;
    T size;
    public:
    Stack(){

    }
    int getSize(){

    }
    bool isEmpty(){

    }
    void push(T element){

    }
    void pop(){

    }
    void top(){

    }
};

int main(){
 
    return 0;
}