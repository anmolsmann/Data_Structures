#include <iostream>
using namespace std;

class queue{
    public:
    //initialze front and rear
    int rear, front;
    //circular array
    int size, *arr;

    queue(int s){
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    void enqueue(int value){
        
    }
};