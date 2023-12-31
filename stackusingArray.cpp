#include <iostream>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;                                   //for the total size of the array/stack;
    public:

    StackUsingArray(){                              // for non dynamic arrays, give argument in constructor
        data = new int[5];
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

    void push(int element){                                 
        if(nextIndex == capacity){
            int *newData = new int[2*capacity];     // dynamic array
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

    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        return data[nextIndex-1];
    }
};

int main(){
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    cout<<s.size()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.top()<<endl;

    return 0;
}