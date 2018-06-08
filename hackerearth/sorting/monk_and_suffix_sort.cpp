#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int a;
    cin>>a;
    vector<string>arr;
    for(int i=0;i<s.size();i++){
        string str=s.substr(i,s.size()-i);
        arr.push_back(str);
    }
    sort(arr.begin(),arr.end());
    cout<<arr[a-1]<<endl;
    return 0;
}