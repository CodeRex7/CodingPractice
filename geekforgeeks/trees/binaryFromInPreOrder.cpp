#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
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

int search(char in[], int start, int end, char data){
    for(int i=start;i<end;i++){
        if(in[i]==data)
            return i;
    }
}

Node* buildTree(char in[], char pre[], int start, int end){
    static int preIndex=0;

    if(start>end)
        return NULL;

    Node* inTemp= newNode(pre[preIndex++]);

    //No child node in this node 
    if(start == end)
        return inTemp;

    int inIndex = search(in, start, end, inTemp->data);

    inTemp->left = buildTree(in, pre, start, inIndex-1);
    inTemp->right = buildTree(in, pre, inIndex+1, end);

    return inTemp;

}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in);
    Node* root = buildTree(in, pre, 0, len-1);

    inorder(root);
 
    return 0;
}
