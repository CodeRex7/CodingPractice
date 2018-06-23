#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int count;
    Node *right,*left;
};

Node* newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->count=1;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void inorder(Node* temp){
    if(!temp)
        return;
    inorder(temp->left);
    cout<<temp->data<<" ("<<temp->count<<") ";
    inorder(temp->right);
}

Node* insert(Node* temp,int data){
    if(temp == NULL)
        return newNode(data);
    if(temp->data == data)
    {
        (temp->count)++;
        return temp;
    }
    if(data>temp->data)
        temp->right=insert(temp->right,data);
    if(data<temp->data)
        temp->left=insert(temp->left,data);
    return temp;
}

Node* minValueNode(Node* temp){
    Node* current=temp;
    while(current->left != NULL){
        current= current->left;
    }
    return current;
}

Node* deleteNode(Node* root,int data){
    if(root== NULL)
        return root;
    if(data > root->data)
        root->right = deleteNode(root->right,data);
    else if(data < root->data)
        root->left = deleteNode(root->left,data);
    else
    {
        if(root->count>1){
            (root->count)--;
            return root;
        }

        if(root->left == NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }

        Node *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);
 
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 12\n");
    root = deleteNode(root, 12);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 9\n");
    root = deleteNode(root, 9);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    return 0;
}
