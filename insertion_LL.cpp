#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

void push(Node** head_ref, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void insertSpecific(Node *prev_node, int new_data){
	if(prev_node == NULL){
		cout<<"The given previous node cannot be null"<<endl;
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node** head_ref, int new_data){
	Node* new_node = new Node();
	Node *last = (*head_ref);
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL){
		last = last->next;
	}
	last->next = new_node;
	return;
}

void print(Node *node){
	while(node != NULL){
		cout<<" "<<node->data;
		node = node->next;
	}
}

int main(){
	Node *head = NULL;
	push(&head, 5);
	push(&head, 7);
	push(&head, 8);
	insertSpecific(head->next, 9);
	append(&head,3);
	
	cout<<"Created linked list is: "<<endl;
	print(head);
	
	return 0;
}
