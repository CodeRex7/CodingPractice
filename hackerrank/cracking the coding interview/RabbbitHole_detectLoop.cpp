/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    
    Node *temp=head;
    if(temp==NULL)
        return false;
    else
    {
        while(temp && head && temp->next){
            
            temp=temp->next;
            
            temp=temp->next;
            
            head=head->next;
            if(head==temp)
            {
                return true;
            }
        }
        return false;
    }
}