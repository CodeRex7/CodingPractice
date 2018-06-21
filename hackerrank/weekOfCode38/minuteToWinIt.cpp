#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,k;
    cin>>n>>k;
    map<ll,ll>arr;
    ll i=0,ax=0;
    for(i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        arr[(a-i*k)]++;
        ax=max(ax,arr[a-i*k]);
    }   
    cout<<n-ax<<endl;
}