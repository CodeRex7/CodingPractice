#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll X[2000005],Y[2000005];
ll counts=0;
void calcsubarray(vector<ll>a, ll x[], ll n, ll c)
{
    for (ll i=1; i<(1<<n); i++) //maximum range of subarray can be 2 to the power of n
    {
        ll s = 0;
        for (ll j=0; j<n; j++){
            if (i & (1<<j))     //this gets activated only when the position say "011" it takes sum of 2 values.
                    s = s ^ a[j+c];
        }            
        if(s==0)
            counts++;
        x[i]=s;
    }
}


int main()
{
    ll n;
    cin>>n;
    vector<ll>A;
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        A.push_back(a);
    }
    calcsubarray(A, X, n/2, 0);         // subarray sum divided into first n/2 elements.
    calcsubarray(A, Y, n-n/2, n/2);     // subarray sum divided into remaining elements.
    ll size_X = 1<<(n/2);
    ll size_Y = 1<<(n-n/2);
    sort(Y,Y+size_Y);
    
    /*for (ll i=1; i<size_X; i++)
    {
        for(ll j=1; j<size_Y;j++){
            if((X[i]^Y[j])==0)
                counts++;
        }
    }*/
    map<ll,ll>map;
    for(ll i=1;i<size_X;i++){
        map[X[i]]++;
    }
    for(ll i=1;i<size_Y;i++){
        if(map[Y[i]]>0)
            counts+=map[Y[i]];
    }
    
    cout<<counts<<endl;
    return 0;
}