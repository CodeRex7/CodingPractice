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
    cin.ignore();
    node* head = NULL;
    for(int i=1;i<=t;i++){
        string s;
        getline(cin,s);
        int it=0;string text="";
        while(s[it]!=' ')
        {
            text+=s[it];
            it++;
        }
        it+=1;
        if(text=="add")
        {
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
                        l->count=0;
                        temp->m[s[it]]=l;
                    }
                    temp = temp->m[s[it]];
                    temp->count=temp->count+1;
                    //cout<<"cw"<<temp->count<<endl;
                    it++;
                }
            temp->end = true;
        }
        else if(text=="find")
        {
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
                        cout<<"0"<<endl;
                        flag=1;
                        break;
                    }
                    temp = temp->m[s[it]];
                    it++; 
                    if (temp == NULL)
                    {
                        cout<<"0"<<endl;
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    cout<<temp->count<<endl;
                
            }
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
