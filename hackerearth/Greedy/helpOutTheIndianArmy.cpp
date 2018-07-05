#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll n,s,e;
    cin>>n>>s>>e;
    map<ll,ll>dist;
    while(n--){
        ll m,q;
        cin>>m>>q;
        dist.insert(make_pair(m-q,m+q));
    }
    ll sum=0;
    ll rear=s;
    for(auto i=dist.begin();i!=dist.end();i++)
    {   
      //  cout<<i->first<<" "<<i->second<<" "<<sum<<endl;
        if((i->first)>rear && (i->first)<e)
            sum+=((i->first)-rear);
        if(i->first<e)
            rear=max(i->second,rear);
    }
    if(e>rear)
        sum+=(e-rear);
    cout<<sum<<endl;    
    return 0;
}