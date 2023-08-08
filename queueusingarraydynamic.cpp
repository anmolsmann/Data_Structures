#include <iostream>
using namespace std;
template <typename T>

class queueArray{
    T *data;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    public:
    queueArray(int s){
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size =0;
        capacity = s;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    void enqueue(T element){
        if(size==capacity){
            T *newData = new T(2*capacity);
            int j=0;
            int i;
            for(i=firstIndex; i<capacity; i++){
                newData[j] = data[i];
                j++;
            } 
            for (j = 0; j < firstIndex; j++){
                newData[j] = data[i];
                j++;
            }
            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *=2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1) % capacity;
        if(firstIndex = -1){
            firstIndex = 0;
        }
        size++;
    }
    T front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};

int main(){
    queueArray<int> q(5);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout<<" "<<q.front()<<endl;
    q.enqueue(70);
    return 0;

}