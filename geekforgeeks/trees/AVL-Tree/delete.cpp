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


  // Update the height of the root at the last
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


Node* minValueNode(Node* temp){
    Node* current=temp;
    while(current->left != NULL){
        current= current->left;
    }
    return current;
}

Node* deleteNode(Node* root,int data){
    if(root== NULL)
        return root;
    if(data > root->data)
        root->right = deleteNode(root->right,data);
    else if(data < root->data)
        root->left = deleteNode(root->left,data);
    else
    {
        if(root->left == NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }

        Node *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    if(root==NULL)
      return root;

    root->height=1+max(height(root->left),height(root->right));

    int balance=getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
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
 
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
 
    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);
 
    root = deleteNode(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 
    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);
 
    return 0;
}

