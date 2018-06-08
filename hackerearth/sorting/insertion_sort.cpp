#include <bits/stdc++.h>
using namespace std;
 
int main()
{
int n,i,j,temp;
cin>>n;
int arr[n],brr[n];
for(i=0;i<n;i++)
{
    cin>>arr[i];
    brr[i]=arr[i];
}
for(i=0;i<n;i++)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
    key = arr[i];
    j = i-1;
 
    while (j >= 0 && arr[j] > key)
    {
    arr[j+1] = arr[j];
    j = j-1;
    }
    arr[j+1] = key;
    }
}
 
 
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        if(brr[i]==arr[j])
        cout<<j+1<<" ";
    } 
} 
return 0;
}
