#include <bits/stdc++.h>

using namespace std;



int main()
{
    string a;
    cin>>a;
    string b;
    cin>>b;
    
    vector<int>num(26);
    for(int i=0;i<a.size();i++){
        int x=a[i]-97;
        num[x]++;
    }
    for(int i=0;i<b.size();i++){
        int x=b[i]-97;
        num[x]--;
    }
    int count=0;
    for(int i=0;i<26;i++){
        count+=abs(num[i]);
    }
    cout<<count<<endl;
    return 0;
}
