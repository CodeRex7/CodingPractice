/*
There are 100 different types of caps each having a unique id from 1 to 100.
Also, there are ‘n’ persons each having a collection of a variable number of caps.
One day all of these persons decide to go in a party wearing a cap but to look unique
they decided that none of them will wear the same type of cap.
So, count the total number of arrangements or ways such that none of them is wearing the same type of cap.
Since, number of ways could be large, so output modulo 1000000007 .
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<int>capList[101];
int dp[1025][101];
int allmask;

long long int CountWaysUtil(int mask, int i){
	if(mask == allmask)
		return 1;
	if(i>100)
		return 0;
	if(dp[mask][i] != -1)
		return dp[mask][i];

	long long int ways = CountWaysUtil(mask,i+1);
	int size = capList[i].size();
	for(int j=0;j<size;j++){
		if(mask & (1<<capList[i][j]))
			continue;
		else 
			ways+= CountWaysUtil(mask | (1<<capList[i][j]), i+1);
		ways%=MOD;
	}
	return dp[mask][i]=ways;
}

void CountWays(int n){
	string temp,str;
	int x;
	for(int i=0;i<n;i++){
		getline(cin,str);
		stringstream ss(str);
		while(ss >> temp)
		{
			stringstream s;
			s << temp;
			s >> x;
			capList[x].push_back(i);
 		}
	}
	allmask = (1<<n)-1;
	memset(dp,-1,sizeof dp);
	cout<<CountWaysUtil(0,1)<<endl;
}

int main()
{
	int n;
	cin>>n;
	cin.ignore();
	CountWays(n);
	return 0;
}