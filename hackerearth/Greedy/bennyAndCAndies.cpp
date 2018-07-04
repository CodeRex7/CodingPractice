#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<ll>x(n+1,0);
    vector<ll>arr(n);
    x[0]=0;
    ll p = pow(2,32);
    //cout<<p<<endl;
    ll q = pow(2,8);
    for(ll i=1;i<n+1;i++){
        x[i]=((x[i-1]%m)*a+b)%p;
        arr[i-1]=floor(x[i]/q);
    }
   ll minpos = 0;
    ll maxpos = 0;
    ll profit = 0;
    for(ll i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            profit += arr[i-1]-arr[minpos];
            minpos = i;
        }
        if(i==n-1)
            profit +=arr[i]-arr[minpos];
    }
    cout<<profit<<endl;
    return 0;
}