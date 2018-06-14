#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
    ll n;
    cin>>n;
    vector<ll>arr(100001,0);
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        arr[a]++;
    }
    ll k;
    cin>>k;
    for(ll i=0;i<100001;i++){
        if(arr[i]==k)
            {cout<<i<<endl;break;}
    }
    return 0;
}
