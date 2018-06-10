#include<bits/stdc++.h>
using namespace std;

string longestRepeat(string a)
{
	int n=a.size();
	vector< vector<int> >dp(n+1);
	for(int i=0;i<n+1;i++){
		dp[i].resize(n+1);
			}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<n+1;j++){
			if(a[i-1]==a[j-1] && i!=j)
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);	
			}
		}
	string rev="";
	int i=n,j=n;
	while(i>0 && j>0){
		if(dp[i][j]==1+dp[i-1][j-1])
		{
			rev+=a[i-1];
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j-1])
			i--;
		else
			j--;
	}
	reverse(rev.begin(),rev.end());
	return rev;
}

int main()
{
	string a;
	cin>>a;
	cout<<longestRepeat(a)<<endl;
	return 0;
}