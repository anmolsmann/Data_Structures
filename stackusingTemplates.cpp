#include <iostream>
using namespace std;
template<typename T>

class StackUsingArray{
    T *data;
    int nextIndex;
    int capacity;                                   //for the total size of the array/stack;
    public:

    StackUsingArray(){                              // for non dynamic arrays, give argument in constructor
        data = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }
    }

    void push(T element){                                 
        if(nextIndex == capacity){
            T *newData = new T[2*capacity];     // dynamic array
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    T pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};

int main(){
    StackUsingArray<int> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.top()<<endl;

    return 0;
}