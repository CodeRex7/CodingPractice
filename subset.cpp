#define f first
#define se second
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
ll n,m,d;
cin>>n>>m>>d;
ll a[m];
vector<pair<ll,ll> >b;
for(ll i=0;i<m;i++)
{
    cin>>a[i];
    b.push_back(make_pair(a[i],i));
}
sort(b.begin(),b.end());


vector<ll>v;
for(ll i=0;i<m-1;i++)
{
  if(b[i].f+b[i+1].f<=d)
  {
      v.push_back(b[i].se);
  
      
  }
    
}

if(b[m].f<=d)
{
    v.push_back(b[m].se);
}
ll sum=v.size();

if(sum==0)
{
    ll count=m-n;
    ll j=m-1;
    while(count--)
    {
        a[b[j].se]=-1;
      j--;  
    }
    
    
}
else
{
    ll co=m-n;
while(co--)
{
    a[v[sum-1]]=-1;
    sum=sum-1;
}
}
for(ll i=0;i<m;i++)
{
    
    if(a[i]!=-1)
    {
        
        cout<<a[i]<<" ";
    }
}
}