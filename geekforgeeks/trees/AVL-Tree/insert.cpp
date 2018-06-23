/*	AVL tree is a self-balancing Binary Search Tree (BST)
 *	where the difference between heights of left and right 
 *	subtrees cannot be more than one for all nodes.
 *	We can guarantee an upper bound of O(Logn) for all 
 *	operations. The height of an AVL tree is always O(Logn)
 *	where n is the number of nodes in the tree.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int height;
    Node *right,*left;
};

int height(Node* N){
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(Node* N){
	if(N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

Node* newNode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->height=1;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}

Node* rightRotate(Node* y){
	Node* x=y->left;
	Node* temp=x->right;

	x->right=y;
	y->left=temp;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
    

	return x;//new root
}

Node* leftRotate(Node* x){
	Node* y=x->right;
	Node* temp=y->left;

	y->left=x;
	x->right=temp;

	x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

	return y;//new root

}

Node* insert(Node* temp,int data){
    if(temp == NULL)
        return newNode(data);
    if(data>temp->data)
        temp->right=insert(temp->right,data);
    else if(data<temp->data)
        temp->left=insert(temp->left,data);
    else
    	return temp; //no duplicates

    temp->height = 1 + max(height(temp->left), height(temp->right));
    int balance = getBalance(temp);

    //Left Left Case---------Right Rotation
    if(balance > 1 && data < temp->left->data)
    	return rightRotate(temp);
    //Right Right Case-------Left Rotation
    if(balance < -1 && data > temp->right->data)
    	return leftRotate(temp);
    //Left Right Case--------Left Right Rotation
    if(balance > 1 && data > temp->left->data){
    	temp->left = leftRotate(temp->left);
    	return rightRotate(temp);
    }
    //Right Left Case--------Right Left Rotation 
    if(balance < -1 && data < temp->right->data){
    	temp->right = rightRotate(temp->right);
    	return leftRotate(temp);
    }
    return temp;
}

void preOrder(Node *root)
{
    if(!root)
		return;    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
  Node *root = NULL;
 
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
 
  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);
  cout<<endl<<root->data<<endl;
 
  return 0;
}

