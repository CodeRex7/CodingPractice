#include <bits/stdc++.h>
using namespace std;


int lcs(string a,string b, int m, int n){
	/*if(m==0 || n==0)
		return 0;
	if(a[m-1]==b[m-1])
		return 1+lcs(a,b,m-1,n-1);
	else 
		return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));
		*/
	//Bottom UP tabulation approach instead of only the recursion approach
	int l[m+1][n+1];
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==0 || j==0)
				l[i][j]=0;
			if(a[i-1][j]==a[i][j-1])
				a[i][j]=1+a[i-1][j-1];
			else
				max(a[i][j-1],a[i-1][j]);
		}
	}
	return a[m][n];
}

int main() {
	string a;
	string b;
	cin>>a;
	cin>>b;
	cout<<lcs(a,b,a.size(),b.size())<<endl;
	return 0;
}