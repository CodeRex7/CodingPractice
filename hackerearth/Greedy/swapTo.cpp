#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
void change(vector<ll> &arr, ll end, ll &k){
    for(ll i=end;i>0;i--){
        swap(arr[i],arr[i-1]);
        k--;
        if(k==0)
            return;
    }
}
int main()
{
    ll i,n,k,t;
    cin>>t;
    while(t--){
		cin>>n>>k;
		ll a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=0;i<n;i++){
			ll pos=i;
			for(ll j=i+1;j<n;j++){
				if((j-i)>k)
				break;
				if(a[j]<=a[pos])
				pos=j;
			}
			for(ll j=pos;j>i;j--)
			    swap(a[j],a[j-1]);
			k-=(pos-i);
		}
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
    
    return 0;
}
