#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        set<ll>go;
        for(int j=0;j<n;j++){
            ll a;
            cin>>a;
            go.insert(a);
        }
        if(x==go.size())
            cout<<"Good"<<endl;
        else if(x<go.size())
            cout<<"Average"<<endl;
        else
            cout<<"Bad"<<endl;
    }
    return 0;
}
