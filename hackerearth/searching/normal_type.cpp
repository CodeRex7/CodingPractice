#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll findsub(vector<ll>arr, int n){
    set<ll>lo;
    for(int i=0;i<n;i++){
        lo.insert(arr[i]);
    }
    ll k=lo.size();
    map<ll,ll>vis;
    vector<ll>ans(n);
    
    ll r=0;
    for(ll l=0;l<n;l++){
        while(r<n && vis.size()!=k){
            vis[arr[r]]++;
            r++;
        }
        if(r==n && vis.size()!=k)
            ans[l]=-1;
        else
            ans[l]= r-1;
        vis[arr[l]]--;
        if(vis[arr[l]]==0)
            vis.erase(vis.find(arr[l]));
    }
    
    ll count = 0;
    for(ll i=0;i<n;i++){
        if(ans[i] != -1)
            count = count + (n-ans[i]);
    }
    return count;
    
}
 
int main()
{
    int t;
    cin>>t;
    vector<ll>arr(t);
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    cout<<findsub(arr,t)<<endl;
    return 0;
}