//recusrsive solution P(n)=P(P(n-1))+P(n-P(n-1))
#include<bits/stdc++.h>
using namespace std;

int sequence(int a){
	vector<int>dp(a+1);
	dp[0]=0;
	dp[1]=dp[2]=1;
	for(int i=3;i<=a;i++){
		dp[i]=dp[dp[i-1]]+dp[i-dp[i-1]];
	}
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<sequence(n)<<endl;
	return 0;
}