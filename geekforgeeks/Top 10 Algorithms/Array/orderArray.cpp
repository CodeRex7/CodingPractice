/*
*	Generate all possible sorted arrays from alternate elements of two given sorted arrays.
*	Given two sorted arrays A and B, generate all possible arrays such that first element 
*	is taken from A then from B then from A and so on in increasing order till the arrays
*	exhausted. The generated arrays should end with an element from B.
*/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>arr;
	vector<int>brr;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.pb(a);;
	}
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		brr.pb(a);
	}

	
}