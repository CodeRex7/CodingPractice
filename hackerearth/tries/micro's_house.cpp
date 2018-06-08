#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll field[10001][21];
ll power2[40];
 
struct Trie{
  ll value;
  Trie *arr[2];
};
 
void solve(){
    power2[0] = 1;
    for(ll i = 1; i<=18; i++)
    power2[i] = 2*power2[i-1];
}
 
 
Trie *newNode(){
    Trie *temp =new Trie();
    temp->value=0;
    temp->arr[0]=temp->arr[1]=NULL;
    return temp;
}
 
void insert(Trie *root, ll pre_xor){
    Trie *temp = root;
 
    for (ll i=18; i>=0; i--)
    {
        bool val = pre_xor & (power2[i]);
         if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
 
        temp = temp->arr[val];
    }
 
    temp->value = pre_xor;
}
 
ll query(Trie *root, ll pre_xor){
    Trie *temp = root;
    for (ll i=18; i>=0; i--)
    {
        bool val = pre_xor & (power2[i]);
 
        if (temp->arr[1-val]!=NULL)
            temp = temp->arr[1-val];
 
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor^(temp->value);
}
 
ll maxSubarrayXOR( ll arr[], ll n){
    Trie *root = newNode();
    insert(root,0);
    ll result=0,pre_xor=0;
    for(int i=0;i<n;i++){
        pre_xor=pre_xor^arr[i];
        insert(root,pre_xor);
        result=max(result,query(root,pre_xor));
    }
    return result;
}
 
int main(){
    ios_base::sync_with_stdio;
    ll n,m;
    cin>>n>>m;
    ll loc[10001];
    solve();
    ll maxans=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            cin>>field[i][j];
            field[i][j] = ( field[i][j] ^ field[i][j-1]);
        }
    }
    for(ll i = 1; i<=m; ++i)
    {
        for(ll j = i; j<=m; ++j)
        {
            for(ll k = 1; k<=n; ++k)
            {
                loc[k-1] = (field[k][j]^field[k][i-1]);
            }
            maxans = max(maxans,maxSubarrayXOR(loc, n)); 
        }
    }
    cout<<maxans<<endl;
    return 0;
}
