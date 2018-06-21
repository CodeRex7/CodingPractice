#include<bits/stdc++.h>
#define ll long  long int
#define mp make_pair
using namespace std;

int main(){
    ll n,q;
    cin>>n>>q;
    set< pair<ll,ll> >set;
    map< ll,pair<ll,ll> >map;
    for(ll i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        set.insert(mp(l,r));
    }
    ll rear=0;
    for(auto i=set.begin();i!=set.end();i++){
        if(i==set.begin())
            {
                map.insert(mp(0,mp(i->first,i->second)));
                rear=(i->second-i->first)+1;
            }
        else
        {
            map.insert(mp(rear,mp(i->first,i->second)));
            rear+=(i->second-i->first)+1;
        }
    }
    for(ll i=0;i<q;i++){
        ll query;
        cin>>query;
        auto it=map.upper_bound(query);
        --it;
        ll val=query-(it->first);
        cout<<(it->second.first)+(val-1)<<endl;
    }
    return 0;
}