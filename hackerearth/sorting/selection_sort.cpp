#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<k;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j])
                min=j;
        }
        swap(a[min],a[i]);
    }    
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}