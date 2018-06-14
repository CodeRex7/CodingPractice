#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll>arr(n);
    ll sum=0;
    vector<ll>add(n+1); // this is needed for getting the prefix sum
    for(ll i=0;i<n;i++)
    {    
        cin>>arr[i];
        sum+=arr[i];
        add[i+1]=sum;
    }
    ll low=0,high=n+1,ans=-1;
    while(low<high){
        ll mid=(low+high)/2;
        ll max=0;
        for(ll j=0;j+mid<=n;j++){
            ll presum=add[j+mid]-add[j];
            if(max<presum)
                max=presum;
        }
        if(max<=x)
            low=mid+1;
        else
            high=mid;
    }
    cout<<low-1<<endl; //as 1 extra is addded at the begiinig of add array..this nullifies it
    return 0;
}