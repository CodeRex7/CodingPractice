#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,r;
        cin>>n>>r;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            int t=(i+r)%n;
            cin>>arr[t];    
        }
        for(int j=0;j<n;j++)
            cout<<arr[j]<<" ";
        cout<<endl;
    }    
    return 0;
}
