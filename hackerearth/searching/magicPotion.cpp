#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for (ll i=0;i<n;i++)
		cin>>arr[i];
	
	ll mini=0,cnt=0,sum=0,i=0,j=0;
	
	map <ll,ll> m;
	m[0]++;
	for (;i<n;i++)
	{
		sum+=arr[i];
		while (sum>k)
		{
			sum-=arr[j];
			j++;
		}
		if (sum==k)
		mini=max(i-j+1,mini);
	}
	
	sum=0,i=0;
	for (;i<n;i++)
	{
		sum+=arr[i];
		cnt+=m[sum-k];
		m[sum]++;
	}
	cout<<cnt<<" "<<n-mini<<endl;
}
