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
void storeBSTNodes(Node* root, vector<Node*>&nodes){
    if(!root)
        return;
    storeBSTNodes(root->left,nodes);
    nodes.push_back(root);
    storeBSTNodes(root->right,nodes);
}
Node* buildTreeUtil(vector<Node*>nodes, int start, int end){
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    Node* root= nodes[mid];

    root->left = buildTreeUtil(nodes, start, mid-1);
    root->right = buildTreeUtil(nodes, mid+1, end);

    return root;
}

Node* buildTree(Node* root){
    vector<Node*> nodes;
    storeBSTNodes(root, nodes);

    int n = nodes.size();
    return buildTreeUtil(nodes, 0, n-1);
}
int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root,5);
    insert(root,3);
  
    // print inoder traversal of the BST
    inorder(root);
    cout<<endl;
    preorder(root);
    root = buildTree(root);

    cout<<endl<<"After the build up"<<endl;
    preorder(root);
  
    return 0;
}
