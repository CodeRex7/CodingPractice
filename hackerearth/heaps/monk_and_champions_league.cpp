#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
priority_queue<ll>heap;
int main()
{
    ll row,pep;
    cin>>row>>pep;
    for(ll i=0;i<row;i++){
        ll a;
        cin>>a;
        heap.push(a);
    }
    ll price=0;
    while(pep--){
        ll z=heap.top();
        price+=z;
        heap.pop();
        heap.push(z-1);
    }
    cout<<price<<endl;
    return 0;
}
