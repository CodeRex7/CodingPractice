#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin >>n;
	    map<int,int>a;
	    int g=0;
	    for(int j=0;j<2*n+2;j++){
	        cin>>g;
	        if(a.find(g)==a.end())
	            a.insert(make_pair(g,1));
	        else{
	            auto it=a.find(g);
	            a.erase(it);   
	        }
	    }
	    for(auto it=a.begin();it!=a.end();it++){
	        cout<<it->first<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}