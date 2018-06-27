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

int getMax(Node* temp,int m){
    if(!temp)
        return 0;
    m=max(m,temp->data);
    if(temp->left)
        m=getMax(temp->left,m);
    if(temp->right)
        m=getMax(temp->right,m);
    return m; 
}
int getMaxL(Node* temp){
    if(!temp)
        return 0;
    queue<Node*>q;
    int m=0;
    while(temp){
        m=max(m,temp->data);
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        temp=q.front();
        q.pop();
    }
    return m;
}

void levelorder(Node* root){
    if(!root)
        return;
    queue<Node*>q;
    while(root){
        cout<<root->data<<" ";

        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
        root=q.front();
        q.pop();
    }
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

int findDiameter(Node* root, int &p){
    int left=0,right=0;
    if(!root)
        return 0;
    //if(root->left)
        left=findDiameter(root->left,p);
    //if(root->right)
        right=findDiameter(root->right,p);

    p=max(p,(left+right+1));
    return max(left,right)+1;
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
    cout<<endl;
    levelorder(root);
    int key = 12;
    insert(root, key);
 
    cout << endl;
    cout << "Inorder traversal after insertion:\n";
    inorder(root);
    cout<<endl;
    levelorder(root);
    cout<<endl<<"Max element"<<endl;
    
    cout<<getMax(root,0)<<endl;
    cout<<getMaxL(root)<<endl;

    cout<<"diameter of tree"<<endl;
    int ans=0;
    int p=findDiameter(root,ans);
    cout<<ans<<endl;
 
    return 0;
}
