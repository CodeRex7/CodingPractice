#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,d;
    cin>>n>>d;
    ll sum=0;
    vector<ll>arr(n+1);
    vector<ll>cumm(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
        cumm[i]=sum;
    }
    while(arr[n]==0)
        n--;
    ll high=n,low=0,ans=-1;
    
    while(high>=low){
        ll mid= (high+low)/2;
        bool flag=true;
        ll cache=cumm[mid];
        for(ll i=mid+1;i<=n;i++){
            cache-=d;
            if(cache<0)
                flag=false;
            cache+=arr[i];
        }
        if(flag)
        {
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}