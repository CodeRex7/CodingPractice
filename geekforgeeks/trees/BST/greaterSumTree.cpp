#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right,*left;
};

Node* newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

void inorder(Node* temp){
    if(!temp)
        return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

Node* insert(Node* temp,int data){
    if(temp == NULL)
        return newNode(data);
    if(data>temp->data)
        temp->right=insert(temp->right,data);
    if(data<temp->data)
        temp->left=insert(temp->left,data);
    return temp;
}
void transformTree(Node* root,int &sum){
    if(!root)
        return;

    transformTree(root->right,sum);
    sum+=root->data;
    root->data=sum-root->data;
    transformTree(root->left,sum);
}

int main()
{
    Node *root = NULL;
    root = insert(root,11);
    insert(root,2);
    insert(root,29);
    insert(root,1);
    insert(root,7);
    insert(root,15);
    insert(root,40);
    insert(root,35);
 
    cout << "Inorder Traversal of given tree\n";
    // print inoder traversal of the BST
    inorder(root);
    int sum=0;
    transformTree(root,sum);
 
    cout << "\n\nInorder Traversal of transformed tree\n";
    inorder(root);
  
    return 0;
}
