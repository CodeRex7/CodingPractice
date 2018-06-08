#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int>a,vector<int>b,int m,int n){
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i]<b[j])
            i++;
        else if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else if(a[i]>b[j])
            return 0;
    }
    if(j<n)
    return 0;
    else
    return 1 ;
}

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int m,n;
	    cin>>m>>n;
	    vector<int>a(m);
	    vector<int>b(n);
	    for(int j=0;j<m;j++)
	        cin>>a[j];
	    for(int k=0;k<n;k++)
	        cin>>b[k];
	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
	    if(isSubset(a,b,m,n))
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	}
	return 0;
}