#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
using namespace std;
ll dp[1000007];
 
 
void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  (((F[0][0]%MOD)*(M[0][0]%MOD))%MOD + ((F[0][1]%MOD)*(M[1][0]%MOD))%MOD)%MOD;
  ll y =  (((F[0][0]%MOD)*(M[0][1]%MOD))%MOD + ((F[0][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD;
  ll z =  (((F[1][0]%MOD)*(M[0][0]%MOD))%MOD + ((F[1][1]%MOD)*(M[1][0]%MOD))%MOD)%MOD;
  ll w =  (((F[1][0]%MOD)*(M[0][1]%MOD))%MOD + ((F[1][1]%MOD)*(M[1][1]%MOD))%MOD)%MOD;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
 
void power(ll F[2][2], ll n)
{
  ll i;
  ll M[2][2] = {{1,1},{1,0}};
  for (i = 2; i <= n; i++)
      multiply(F, M);
}
 
ll fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if(dp[n%MOD] != -1)
    return dp[n%MOD];
  if (n == 0)
      return 1;
  if (n == 1)
      return 2;
  power(F, n-1);
  ll L[2]={2,1};
  ll ans=(((F[0][0]%MOD)*(L[0]%MOD))%MOD + ((F[0][1]%MOD)*(L[1]%MOD))%MOD)%MOD;
  dp[n%MOD]=ans;
  return dp[n%MOD];
}
 
int main()
{
    ll t;
    cin>>t;
    memset(dp, -1, sizeof dp); 
    while(t--){
        ll n;
        cin>>n;
        cout<<fib(n)%MOD<<endl;
        }
    return 0;
}
Language: C++14