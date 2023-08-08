#include <iostream>
#define MAXLEN 100
using namespace std;

typedef struct{
    int element[MAXLEN];
    int front, rear;
}queue;

queue init(){
    queue Q;
    Q.front = Q.rear = -1;
    return Q;
}

int size(queue Q){
    return(Q.rear - Q.front +1);
}

int isEmpty(queue Q){
    return((Q.front==1) || (Q.front>Q.rear));
}

int isFull(queue Q){
    return(Q.rear == MAXLEN -1);
}

int front(queue Q){
    if(isEmpty(Q)){
        cout<<"Empty"<<endl;
    }
    else{
        return Q.element[Q.front];
    }
}

queue enqueue(queue Q, int x){
    if(isFull(Q)){
        cout<<"Overflow"<<endl;
    }
    else if(isEmpty(Q)){
        Q.front=Q.rear=0;
        Q.element[Q.rear]=x;
    }
    else{
        ++Q.rear;
        Q.element[Q.rear]=x;
    }
    return Q;
}

queue dequeue(queue Q){
    if(isEmpty(Q)){
        cout<<"Underflow"<<endl;
    }
    else{

        Q.front++;
    }
    return Q;
}

void print(queue Q){
    int i;
    for (i=Q.front ; i <= Q.rear; i++)
    {
        cout<<" "<<Q.element[i]<<"\t";
    }
    
}
int main(){
    queue Q;
    Q=init();
    Q=enqueue(Q,5);
    Q=enqueue(Q,3);
    Q=dequeue(Q);
    Q=enqueue(Q,6);
    Q=enqueue(Q,9);
    Q=enqueue(Q,14);
    cout<<"Current Queue: "<<"\t";
    print(Q);
    cout<<"With front: "<<front(Q)<<"\t";
    cout<<"Size: "<<size(Q)<<endl;
    
    Q=enqueue(Q,5);
    Q=enqueue(Q,8);
    Q=enqueue(Q,4);
    cout<<"Current Queue: "<<"\t";
    print(Q);
    cout<<"With front: "<<front(Q)<<"\t";
    cout<<"Size: "<<size(Q)<<"\t";

    return 0;
}