#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int n,m;
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.first%m < b.first%m)
        return true;
    else if(a.first%m == b.first%m)
        return (a.second<b.second);
    else    
        return false;  
}
int main()
{
    
    cin>>n>>m;
    vector<pair<ll,ll> >ar;
    for(int i=0;i<n;i++)
    {
        ll k;
        cin>>k;
        ar.push_back(make_pair(k,i));
    }
    sort(ar.begin(),ar.end(),cmp);
    for(int i=0;i<n;i++)
        cout<<ar[i].first<<" ";
    return 0;
}
