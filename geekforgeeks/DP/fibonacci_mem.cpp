#include<bits/stdc++.h>
#define ll long long int
#define MAX 100
using namespace std;
vector<ll>lookup(MAX,0);

ll fib(ll n)
{
	if(lookup[n]==0)
	{
		if(n<=1)
			lookup[n]=n;
		else
			lookup[n]=fib(n-1)+fib(n-2);;
	}
	return lookup[n];
}

int main()
{
	int n;
	cout<<"The lookup limit is 100"<<endl;
	cin>>n;
	cout<<fib(n)<<endl;
	return 0;
}