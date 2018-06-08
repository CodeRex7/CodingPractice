#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    unsigned int n;
	    cin>>n;
	    unsigned int rev=0;
	    for(int j=0;j<32;j++){
	        if(n & (1<<j))
	            rev|= (1<<(32-1-j));    
	    }
	    cout<<rev<<endl;
	}
	return 0;
}