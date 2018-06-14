#include<bits/stdc++.h>
#define ll long long int
using namespace std;


bool check(ll tim,ll m,ll n,vector<ll>box,vector<ll>truck)
{
 ll b=0;
 for(ll i=0;i<m;++i)
 {
  for(ll j=0;j<tim && b<n && truck[i]>=box[b];j=j+2)
    b++;
 }
 if(b==n)
    return true;
return false;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>box(n);
    vector<ll>truck(m);
    for(ll i=0;i<n;i++)
        cin>>box[i];
    for(ll i=0;i<m;i++)
        cin>>truck[i];
    sort(box.begin(),box.end());
    sort(truck.begin(),truck.end());
    
    ll low=0,high=2*n,ans=-1;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid,m,n,box,truck)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}