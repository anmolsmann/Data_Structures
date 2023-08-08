#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void insertbeg(Node** head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
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
    insertbeg(&head, 11);
    display(head);
    return 0;
}
