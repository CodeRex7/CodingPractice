#include<bits/stdc++.h>
using namespace std;
vector<bool>prime((100001),true);
void sieve(int m,int n){
    prime[0]=prime[1]=false;
    for(int p=2;p*p<=n;p++)
    {
        if(prime[p]==true){
            for(int i=p*2;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
}
int main() {
	//code
	int t;
	cin>>t;
	
	sieve(2,100000);
	for(int i=0;i<t;i++){
	    int m,n;
	    cin>>m>>n;
	    for(int p=m;p<=n;p++){
        if(prime[p]==true)
            cout<<p<<" ";
    }
    cout<<endl;
	}
	return 0;
}