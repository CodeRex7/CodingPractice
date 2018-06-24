/*
*	Given a string, print all possible palindromic partitions
*/

#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
using namespace std;

bool isPallin(string s, int l, int h){
	while(l<h){
		if(s[l]!=s[h])
			return false;
		l++;
		h--;
	}
	return true;
}

void allPalPartion(vector< vector<string> >&allPal, vector<string>&currPal, int start, int end, string str){
	if(start>=end)	
	{
		allPal.pb(currPal);
		return;
	}

	for(int i=start;i<end;i++){
		if(isPallin(str,start,i))
		{
			currPal.pb(str.substr(start,i-start+1));
			allPalPartion(allPal,currPal,i+1,end,str);
			currPal.pob();
		}
	}
}

int main()
{
	string str;
	cin>>str;

	vector< vector<string> >allPal;
	vector<string>currPal;

	allPalPartion(allPal, currPal, 0, str.size(), str);

	for(int i=0;i<allPal.size();i++)
	{
		for (int j=0; j<allPal[i].size(); j++)
            cout << allPal[i][j] << " ";
        cout << "\n";
	}
	return 0;
}