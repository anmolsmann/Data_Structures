#include <iostream>
using namespace std;

class StackUsingArray{
    int *data;
    int nextIndex;
    int capacity;                           //for the total size of the array/stack;
    public:

    StackUsingArray(int total_size){
        data = new int[total_size];
        nextIndex = 0;
        capacity = total_size;
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
            cout<<"Stack is full"<<endl;
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
    StackUsingArray s(5);
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