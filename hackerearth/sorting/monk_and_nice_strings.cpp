#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    multiset<string>s;
    for(int i=0;i<t;i++){
        string a;
        cin>>a;
        int k=0;
        for(auto it=s.begin();it!=s.end();it++)
            k+= (*it<a);   
        cout<<k<<endl;
        s.insert(a);
    }
    return 0;
}