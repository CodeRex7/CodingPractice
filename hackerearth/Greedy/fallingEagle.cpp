#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>arr(n);
        cin>>arr[0];
        ll sum = 0;
        for(int i=1;i<n;i++){
            cin>>arr[i];
            sum += max(arr[i],arr[i-1]);
        }
        cout<<sum<<endl;
    }
}