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

void deep_deletion(Node *root,Node *d_node)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if (temp->right){
            if (temp->right == d_node){
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->right);
        }
 
        if (temp->left){
            if (temp->left == d_node){
                temp->left=NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
void deletion(Node* root, int data){
    queue<Node*>q;
    q.push(root);
    Node *temp;
    Node* key_Node= NULL;
    while(!q.empty()){
        temp=q.front();
        q.pop();

        if(temp->data==data)
            key_Node=temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    int x=temp->data; //Right most last element
    key_Node->data=x;
    deep_deletion(root,temp);
    //delete(temp); Cant.. As we have to make thee previous as Null. then we can delete this node.
}



int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before deletion : ";
    inorder(root);
 
    int key = 11;
    deletion(root, key);
 
    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);
 
    return 0;
}