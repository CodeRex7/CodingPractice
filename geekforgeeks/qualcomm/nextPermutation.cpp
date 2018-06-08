#include <bits/stdc++.h>
using namespace std;


int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    vector<int>a(n);
	    for(int j=0;j<n;j++)
	        cin>>a[j];
	    int flag=0,k=a.size()-1; 
	    for(;k>0;k--){
	        if(a[k-1]<=a[k])
	        {
	            flag=1;
	            sort(a.begin()+k,a.end());
	            int m=k;
	            //cout<<m<<endl;
	            for(;m<a.size();m++){
	                if(a[m]>a[k-1])
	                    break;
	            }
	            swap(a[m],a[k-1]);
	            break;
	        }
	    }
	    if(!flag){
	        sort(a.begin(),a.end());
	    }
	    
	    for(int m=0;m<a.size();m++){
	        cout<<a[m]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
