#include <iostream>
using namespace std;

class Node{
    public:
    int key, height;
    Node* left;
    Node* right;
};

int getHeight(Node* n){
    if(n==0)
        return 0;
    return n->height;
} 

Node* createNode(int key){
    Node* node = new Node;
    node->key = key;
    node->right = NULL;
    node->left = NULL;
    node->height = 1;

    return node;
}

int getBalanceFactor(Node* n){
    if(n=NULL){
        return 0;
    }
    return (getHeight(n->left) - getHeight(n->right));
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* c2 = x->right;

    x->right = y;
    y->left = c2;

    y->height = max(getHeight(y->left), getHeight(y->right)) +1;
    x->height = max(getHeight(x->left), getHeight(x->right)) +1;

    return x; 
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* c2 = y->left;

    y->left = x;
    x->right = c2;

    y->height = max(getHeight(y->left), getHeight(y->right)) +1;
    x->height = max(getHeight(x->left), getHeight(x->right)) +1;

    return y; 
}



int main(){
 
    return 0;
}