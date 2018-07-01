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
void preorder(Node* temp){
    if(!temp)
        return;
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
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

void inorderTraversal(Node* root, vector<int>&arr){
    if(!root)
        return;
    inorderTraversal(root->left,arr);
    arr.push_back(root->data);
    inorderTraversal(root->right,arr);
}

void minHeap(Node* root, vector<int>arr, int &i){
    if(!root)
        return;
    root->data=arr[i++];
    minHeap(root->left,arr,i);
    minHeap(root->right,arr,i);
}

void convertToHeap(Node* root){
    vector<int>arr;
    int i=0;
    inorderTraversal(root,arr);
    minHeap(root,arr,i);
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
    inorder(root);
    
    convertToHeap(root);
 
    cout << "\n\nPreorder Traversal of transformed tree\n";
    preorder(root);
  
    return 0;
}
