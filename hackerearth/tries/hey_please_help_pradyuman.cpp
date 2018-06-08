#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
struct node{
    struct node* children[26];
    bool iseow; 
};
 
node* getNode(){
    node* pnode = new node;
    pnode->iseow = false;
    for(int i=0;i<26;i++){
        pnode->children[i] = NULL;
    }
    return pnode;
}
node* insert(node* root,string key){
    node* pcrawl = root;
    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(index<0)
            index = key[i] - 'A';
        //cout<<key[i]<<endl;
        if(!pcrawl->children[index]){
            pcrawl->children[index] = getNode();
        }
        pcrawl = pcrawl->children[index];
    }
    pcrawl->iseow = true;
}
 
node* search(node* root,string key){
    node* pcrawl = root;
    for(int i=0;i<key.length();i++){
        int ind = key[i] - 'a';
        //cout<<key[i]<<endl;
        if(!pcrawl->children[ind])
            return NULL;
        pcrawl = pcrawl->children[ind];
    }
    if(pcrawl == NULL)
        return NULL;
    else
        return pcrawl;
}
vector<string>store(0);
 
void display(struct node* root, char str[], int level)
{
    if (root->iseow == true) {
        str[level] = '\0';
        store.push_back(str);
    }
 
    int i;
    for (i = 0; i < 26; i++) {
        if (root->children[i]) {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    node* root = getNode();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(root,s);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        string p;
        cin>>p;
        node* autos = search(root,p);
        if(autos == NULL){
            cout<<"No suggestions"<<endl;
            insert(root,p);
        }
        else{
            char str[20];
            display(autos,str,0);
            //cout<<store.size()<<endl;
            if(!store.empty()){
            for(int j=0;j<store.size();j++){
                
                    string b = p + store[j];
                    cout<<b<<endl;
                
            }
            }
            store.clear();
        }
    }
}
