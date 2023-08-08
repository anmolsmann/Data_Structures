#include <iostream>
using namespace std;

class queue{
    public:
    int size, f, r;
    int* arr;
};

int isEmpty(queue* q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}

int isFull(queue* q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(queue* q, int val){
    if(isFull(q)){
        cout<<"The Queue is full"<<endl;
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int deQueue(queue* q){
    int a=-1;
    if(isEmpty(q)){
        cout<<"Queue is empty"<<endl;
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = new int;

    int i=0;
    int node;
    int visited[7] = {0,0,0,0,0,0,0};
    int arr[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    cout<<i;
    visited[i] = 1;
    enqueue(&q, i); //for exploration

    while(!isEmpty(&q)){
        int node = deQueue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(arr[node][j]==1 && visited[j]==0){
                cout<<j;
                visited[j] = 1;
                enqueue(&q, j); 
            }
        }
        
    }
    return 0;

}

