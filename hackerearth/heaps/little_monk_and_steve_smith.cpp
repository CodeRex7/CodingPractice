#include<bits/stdc++.h>
#define ll long long int
using namespace std;
struct cmp{
bool operator()(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first==b.first && a.second>b.second)
        return true;
    else if(a.first<b.first)
        return true;
    else
        return false;
}
};
 
int main(){
    ll n,k;
    cin>>n>>k;
    priority_queue< pair<ll,ll>,vector< pair<ll,ll> > , cmp>min;
    for(ll i=0;i<n;i++){
        ll b;
        cin>>b;
        min.push(make_pair(b,i+1));
    }
    for(int i=0;i<k;i++){
        pair<ll,ll> ans=min.top();
        cout<<ans.second<<" ";
        ll ball=ans.first-1;
        ll qwe=ans.second;
        min.pop();
        min.push(make_pair(ball,qwe));
    }
    return 0;
}
