#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll sum(ll a){
    ll ne=a,sum=0;
    while(a>0){
        sum+=a%10;
        a=a/10;
    }
   //cout<<ne<<" "<<sum<<endl;
    return sum;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll low=1;
        ll high=n;
        ll mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if(mid<m+sum(mid))
            {
                low=mid+1;   
            }
            else
            {
                high=mid-1;
            }
        }
        if(mid-sum(mid)<m && mid==n)
            cout<<0<<endl;
        else if(mid-sum(mid)<m && mid!=n)
            cout<<n-mid<<endl;
        else
            cout<<n-mid+1<<endl;
        }
    return 0;
}