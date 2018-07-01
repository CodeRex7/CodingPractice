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

/*Order of n */
Node* constructTree(int pre[],int &preIndex, int key, int min, int max, int size){
    if(preIndex >= size)
        return NULL;
    Node* root=NULL;
    if(key>min && key<max){
        root=newNode(key);
        preIndex+=1;

        if(preIndex < size){
            root->left=constructTree(pre, preIndex, pre[preIndex], min, key, size);
            root->right=constructTree(pre, preIndex, pre[preIndex], key, max, size);
        }
    }
return root;
}

Node* constructTree(int pre[], int size){
    stack<Node*>stack;
    Node* root= newNode(pre[0]);
    stack.push(root);
    for(int i=1;i<size;i++){
        Node* temp = NULL;

        while(!stack.empty() && pre[i]>(stack.top()->data)){
            temp=stack.top();
            stack.pop();
        }
        if(temp){
            temp->right = newNode(pre[i]);
            stack.push(temp->right);       
        }else{
            stack.top()->left = newNode(pre[i]);
            stack.push(stack.top()->left);
        }    
    }
    return root;
}

int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
    int preIndex=0;
    //Node *root = constructTree(pre, preIndex, pre[0], INT_MIN, INT_MAX, size);
    Node *root = constructTree(pre,size);
 
    printf("Inorder traversal of the constructed tree: \n");
    inorder(root);
 
    return 0;
}
