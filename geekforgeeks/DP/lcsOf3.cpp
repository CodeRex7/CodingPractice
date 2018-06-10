#include <bits/stdc++.h>
using namespace std;


int lcs(string a,string b, string c, int m, int n, int o){

	//Bottom UP tabulation approach instead of only the recursion approach
	int l[m+1][n+1][o+1];
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			for(int k=0;k<o+1;k++){
				if(i==0 || j==0 || k==0)
					l[i][j][k]=0;
				if(a[i-1]==b[j-1] || a[i-1]==c[k-1])
					l[i][j]=1+l[i-1][j-1][k-1];
				else
					max(l[i][j-1][k],l[i-1][j][k],l[i][j][k-1]);
			}
		}
	}
	return a[m][n];
}

int main() {
	string a;
	string b;
	string c;
	cin>>a;
	cin>>b;
	cin>>c;
	cout<<lcs(a,b,c,a.size(),b.size(),c.size())<<endl;
	return 0;
}