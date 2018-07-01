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

void storeInorder(Node* root, vector<int>&arr, int &x){
    if(!root)
        return;
    storeInorder(root->left,arr,x);
    arr[x++]=root->data;
    storeInorder(root->right,arr,x);
}

vector<int> merge(vector<int>arr1, vector<int>arr2, int m, int n){
    vector<int>mergedArr(m+n);

    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(arr1[i] < arr2[j])
            mergedArr[k] = arr1[i++];
        else
            mergedArr[k] = arr2[j++];
        k++;
    }
    while(i < m){
        mergedArr[k] = arr1[i++];
        k++;
    }
    while(j < n){
        mergedArr[k] = arr2[j++];
        k++;
    }
    return mergedArr;
} 

Node* sortedArrayToBst(vector<int>mergedArr, int start, int end){
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    Node* root = newNode(mergedArr[mid]);

    root->left = sortedArrayToBst(mergedArr, start, mid-1);
    root->right = sortedArrayToBst(mergedArr, mid+1, end);

    return root;
}

Node* mergeTrees(Node* root1, Node* root2, int m, int n){
    vector<int>arr1(m);
    vector<int>arr2(n);
    int i=0;
    storeInorder(root1, arr1, i);
    int j=0;
    storeInorder(root2, arr2, j);
    vector<int> mergedArr = merge(arr1, arr2, m, n);

    return sortedArrayToBst(mergedArr, 0, m+n-1);
}
int main()
{
    Node *root1  = NULL;
    root1 = insert(root1,100);
    insert(root1,50);
    insert(root1,300);
    insert(root1,20);
    insert(root1,70);
    
    Node *root2  = NULL;
    root2 = insert(root2,80);
    insert(root2,40);
    insert(root2,20);
    
    Node* root = mergeTrees(root1, root2, 5, 3);
    // print inoder traversal of the BST
    inorder(root);
  
    return 0;
}
