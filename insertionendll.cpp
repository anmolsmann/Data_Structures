#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};
void insertLast(Node** head, int data){

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(*head==NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
}
void display(Node* node){
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

int main(){
    Node* head = NULL;
    Node* first = NULL;
    Node* second = NULL;
    Node* third = NULL;


    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 15;
    head->next = second;

    second->data = 30;
    second->next = third;

    third->data = 45;
    third->next = NULL;

    cout<<"Linked list: ";
    insertLast(&head,50);
    display(head);
    return 0;
}