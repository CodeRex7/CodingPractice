/*
*	Rearrange the elements of array in zig-zag fashion in O(n) time.
*	The converted array should be in form a < b > c < d > e < f
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void zigzag(vector<int> &arr){
	bool flag=true;
	for(int i=0;i<arr.size()-1;i++){
		//< expected if not then swap
		if(flag){
			if(arr[i]>arr[i+1])
				swap(arr[i],arr[i+1]);
		}
		//> expected if not then swap
		else{
			if(arr[i]<arr[i+1])
				swap(arr[i],arr[i+1]);
		}
		flag=!flag;
	}
}

int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	zigzag(arr);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;	
}