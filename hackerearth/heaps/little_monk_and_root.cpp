#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    double sum=0;
    priority_queue<ll>max;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        max.push(a);
        sum+=a;
    }
    double ans=sum/n;
    printf("%0.6f ",ans);
    while(k--){
        double sap=max.top();
        sum-=sap;
        //cout<<sap<<endl;
        sap=ceil(sap/3);
        max.pop();
        max.push(sap);
        sum+=sap;
        //cout<<sap<<"sap/3"<<endl;
       
    }
    ans=sum/n;
    printf("%0.6f ",ans);
    return 0;
}
Language: C++14