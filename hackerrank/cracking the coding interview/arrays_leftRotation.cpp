#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n=0,k=0;
    cin>>n>>k;
    vector<int>arr(n);
    /*for(int i=0;i<n;i++){
        cin>>arr[i];
    }*/
    for(int i=0; i<n; i++){
    int loc= (i + (n - k)) % n;
    cin>>arr[loc];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
