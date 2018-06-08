#include <bits/stdc++.h>
using namespace std;
 
struct node{
    unordered_map<char,node*> m;
    bool end;
    int count;
};
 
int main()
{
    
    int t;
    cin>>t;
    int q;
    cin>>q;
    cin.ignore();
    node* head = NULL;
    for(int i=1;i<=t;i++){
        string s;
        cin>>s;
        int val;
        cin>>val;
        int it=0;string text="";
            if(head == NULL)
            {
                node* n=new node;
                n->end=false;
                n->count=0;
                head=n;
            }
            
                node* temp=head;
                while(it<s.size())
                {
                    if(temp->m.find(s[it])==temp->m.end())
                    {
                        node* l = new node;
                        l->end = false;
                        l->count=val;
                        temp->m[s[it]]=l;
                    }
                    temp = temp->m[s[it]];
                    if(val>temp->count)
                        temp->count=val;
                    it++;
                }
            temp->end = true;
    }
        ///////////////////////////////////////////////////////////////////////
        for(int i=0;i<q;i++){
            string s;
            cin>>s;
            int it=0;
            if(head==NULL)
            {
                cout<<"0"<<endl;
            }
            else
            {
                node* temp=head;
               // node* temp1=temp;
                int flag=0;
                while(it<s.size())
                {
                   // temp1=temp;
                    //cout<<temp1->count<<endl;
                    
                    if(temp->m.find(s[it])==temp->m.end())
                    {
                        cout<<"-1"<<endl;
                        flag=1;
                        break;
                    }
                    temp = temp->m[s[it]];
                    it++; 
                    if (temp == NULL)
                    {
                        cout<<"-1"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    cout<<temp->count<<endl;
            }  
        }
    return 0;
}
