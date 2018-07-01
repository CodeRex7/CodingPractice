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

void insert(Node* temp,int data){
    queue<Node*>q;
    q.push(temp);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(!temp->left)
        {temp->left= newNode(data);break;}
        else
            {q.push(temp->left);}
        if(!temp->right)
        {temp->right= newNode(data);break;}
        else
            {q.push(temp->right);}     
    }
}

void storeinorderInSet(Node* root,set<int>&s){
    if(!root)
        return;
    storeinorderInSet(root->left,s);
    s.insert(root->data);
    storeinorderInSet(root->right,s);
}

void setToBST(set<int>&s, Node* root){
    if(!root)
        return;
    setToBST(s,root->left);
    
    auto it = s.begin();
    root->data = *it;
    s.erase(it);

    setToBST(s,root->right);
}

void binaryTreeToBST(Node* root){
    set<int>s;
    storeinorderInSet(root, s);

    setToBST(s, root);
} 

int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
 
    cout << "Inorder traversal before insertion:\n";
    inorder(root);
    binaryTreeToBST(root);
    cout << "Inorder traversal of BST is: " << endl;
    inorder(root);
 
    return 0;
}
