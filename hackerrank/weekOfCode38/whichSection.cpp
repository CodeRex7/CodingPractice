#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll n,k,m;
        cin>>n>>k>>m;
        vector<ll>arr(m);
        ll sum=0;
        for(ll i=0;i<m;i++){
            cin>>arr[i];
            
        }
        for(ll i=0;i<m;i++){
            sum+=arr[i];
            if(sum>=k)
            {
                cout<<i+1<<endl;
                break;
            }
        }
        
    }
    return 0;
}