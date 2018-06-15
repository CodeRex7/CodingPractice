#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll X[2000005],Y[2000005];

void calcsubarray(vector<ll>a, ll x[], ll n, ll c)
{
    for (ll i=0; i<(1<<n); i++) //maximum range of subarray can be 2 to the power of n
    {
        ll s = 0;
        for (ll j=0; j<n; j++)
            if (i & (1<<j))     //this gets activated only when the position say "011" it takes sum of 2 values.
                s += a[j+c];
        x[i]=s;
    }
}


int main()
{
    ll n;
    cin>>n;
    ll S;
    cin>>S;
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
    ll max=0;

    //Finding the combination which is less than S 
    for (ll i=0; i<size_X; i++)
    {
        if (X[i] <= S)
        {
            // returns the first address which has value greater than or equal to S-X[i]. 
            ll p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;
 
            if (p == size_Y || Y[p] != (S-X[i])) // the value is not found so just the lower one.
                p--;
 
            if ((Y[p]+X[i]) > max)
                max = Y[p]+X[i];
        }
    }
    cout<<max<<endl;
    return 0;
}