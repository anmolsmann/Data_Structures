#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* link;
};

Node* top;
void push(int data){
    Node* temp = new Node;
    if (!temp)
    {
        cout<<"Stack Overflow"<<endl;
        exit(1);
    }
    temp->data = data;
    temp->link = top;
    top = temp;
    
}

void display(){
    Node* temp;
    if (top == NULL)
    {
        cout << "Stack Underflow"<<endl;
        exit(1);
    }
    else{
        temp = top;
        while(temp!=NULL){
            cout<<temp->data<<"-> ";
            temp = temp->link;
        }
    }
}

int main(){

    push(11);
    push(22);
    push(33);
    push(44);

    display();
    return 0;
}