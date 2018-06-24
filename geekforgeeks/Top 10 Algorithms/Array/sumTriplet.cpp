/*
*	Count triplets with sum smaller than a given value
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;


int countTriplets(vector<int> arr,int sum){
	int ans=0;
	int n=arr.size();
	for(int i=0;i<n-2;i++){
		int l=i+1,h=n-1;
		while(l<h){
			if(arr[i]+arr[l]+arr[h]>=sum)
				h--;
			else{
				ans+=(h-l);//these many possible triplets can be formed with same i,l and varying h.
				l++;
			}
		}
	}
	return ans;
}

int main(){
	int n,sum;
	cin>>n>>sum;
	vector<int>arr;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	cout<<countTriplets(arr,sum)<<endl;
}