#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
}*top;

void init(){
    top == NULL;
}

void push(int value){
    Node* newNode;
    newNode = new Node();
    newNode->data = value;
    if (top==NULL)
    {
        newNode->next==NULL;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

void pop(){
    if (top==NULL)
    {
        cout<<"Undeflow condition"<<endl;
    }
    else
    {
        Node* temp=top;
        cout<<"Deleted element: "<<temp->data;
        top = temp->next;
        free(temp);
    }
}

void display(){
    if (top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is: ";
        Node* temp = top;
        while (temp->next!=NULL)
        {
            cout<<" "<<temp->data;
            temp = temp->next;
        }
        cout<<" "<<temp->data;
    }
}

int main(){
    int choice, value;
    while(1){
        cout<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Display"<<endl<<"4.Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to insert: "<<endl;
            cin>>value;
            push(value);
            break;
        
        case 2:
            cout<<"Popped element is: ";
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}