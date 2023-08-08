#include <iostream>
using namespace std;

class BST{
    public:
    int data, level;
    BST *left, *right;

    BST() : data(0), left(NULL), right(NULL)
        {
    }

    BST(int value){
        data = value;
        right = left = NULL;
    }

    BST *insert(BST *root, int value){
        if(!root){
            return new BST(value);
        }
        if (value>root-> data){
            root->right = insert(root->right, value);
        }
        else if(value<root->data){
            root->left = insert(root->left,value);
        }
        return root;
    }

    void Inorder(BST *root){
        if(!root){
            return;
        }
        Inorder(root->left);
        cout<<root->data<<endl;
        Inorder(root->right);
    }

};
int main(){
    BST b, *root=NULL;
    root = b.insert(root, 50);
    b.insert(root, 20);
    b.insert(root, 30);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 80);

    b.Inorder(root);

    return 0;
}