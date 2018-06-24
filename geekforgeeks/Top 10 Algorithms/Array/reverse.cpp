/*
*	Reverse an array without affecting special characters
*/

#include<bits/stdc++.h>
using namespace std;

bool isAlphabet(char ch){
	if((ch>='A' && ch<='Z')||(ch>='a' && ch<='z'))
		return true;
	return false;	
}

int main()
{
	string s;
	cin>>s;

	int l=0;
	int r=s.size()-1;

	while(l<r){
		if(!isAlphabet(s[l]))
			l++;
		else if(!isAlphabet(s[r]))
			r--;
		else{
			swap(s[l],s[r]);
			l++;
			r--;
		}
	}
	cout<<s<<endl;
}