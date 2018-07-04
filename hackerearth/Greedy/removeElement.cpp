#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

bool cmp(ll a, ll b){
    if(a>b)
        return true;
    else
        return false;
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>arr(n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
                cin>>arr[i];
        }
        sort(arr.begin(),arr.end(),cmp);
        ll j=1;
        for(ll i=0;i<n;i++){
            sum+=(arr[i]%mod*j%mod)%mod;
            j=j*(i+2)%mod;
        }
        cout<<sum%mod<<endl;
    }
    return 0;
}