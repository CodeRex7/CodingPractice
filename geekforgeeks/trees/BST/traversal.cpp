/*
*	Traversals without Recursion using Stack
*   Inorder Traversal using stack
*   Preorder Traversal uing stack
*   Postorder Traversal using two stacks
*   Postorder Traversal using a stack
*   levelorder Traversal using queue
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *right;
	Node *left;
};

Node* newNode(int data){
	Node* temp= new Node;
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
}

Node* insert(Node* root,int data){
	if(root == NULL)
		return newNode(data);
	if(data < root->data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	return root;
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
    return root;
}

void inorder(Node* root){
	if (root == NULL)
       return;
    stack<Node*>stack;
    Node* curr = root;
    while(curr!=NULL || !stack.empty()){
        if(curr!=NULL){
            stack.push(curr);
            curr=curr->left;
        }
        else{
            curr=stack.top();
            stack.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
}

void preorder(Node* root){
    if (root == NULL)
       return;
    stack<Node*>stack;
    stack.push(root);

    while(!stack.empty()){
        Node* temp=stack.top();
        cout<<temp->data<<" ";
        stack.pop();
        if(temp->right)
            stack.push(temp->right);
        if(temp->left)
            stack.push(temp->left);
    }
}

void postorder(Node* root){
    if(root == NULL)
        return;
    stack<Node*>first;
    stack<Node*>second;

    first.push(root);
    while(!first.empty()){
        Node* temp=first.top();
        second.push(temp);
        first.pop();
        if(temp->left)
            first.push(temp->left);
        if(temp->right)
            first.push(temp->right);
    }
    while(!second.empty()){
        Node* temp=second.top();
        cout<<temp->data<<" ";
        second.pop();
    }
}

Node* peek(stack<Node*> stack)
{
    if (stack.empty())
        return NULL;
    return stack.top();
}

void adv_postorder(Node* root){
    if(root == NULL)
        return;
    stack<Node*>stack;
    do{
        while(root){
            if(root->right)
                stack.push(root->right);
            stack.push(root);

            root=root->left;
        }

        root=stack.top();
        stack.pop();

        if(root->right && peek(stack)==root->right){
            stack.pop();
            stack.push(root);
            root=root->right;
        }
        else{
            cout<<root->data<<" ";
            root=NULL;
        }
    }while(!stack.empty());
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

int main(){
	
	Node* root=newNode(60);
	
	insert(root,50);
	insert(root,70);
	insert(root,40);
	insert(root,30);
	insert(root,80);
	insert(root,75);
	insert(root,65);
	insert(root,45);
	insert(root,55);
	insert(root,90);
	insert(root,67);

	printf("traversal of the given tree \n");
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    adv_postorder(root);
 
    printf("\nDelete 75\n");
    root = deleteNode(root, 75);
    printf("traversal of the modified tree \n");
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    adv_postorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("traversal of the modified tree \n");
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    adv_postorder(root);
 
    printf("\nDelete 60\n");
    root = deleteNode(root, 60);
    printf("traversal of the modified tree \n");
    inorder(root);
    cout<<endl;            
	preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    adv_postorder(root);

	cout<<endl;
	return 0;
}