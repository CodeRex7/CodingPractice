#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
priority_queue< pair<ll,int>, vector< pair<ll,int> >, greater< pair<ll,int> > > heap;
ll already[100002];
ll monk[100002];
ll ans[100002];
vector<ll>price[100002];
 
int main()
{
    int c,n,k;
    cin>>c>>n>>k;
    for(int i=0;i<k;i++){
        cin>>already[i];
        heap.push(make_pair(already[i],i));
        price[i].push_back(already[i]);
    }
    for(int i=k;i<c;i++){
        heap.push(make_pair(0,i));
    }
    for(int i=0;i<n;i++){
        cin>>monk[i];
    }
    
    pair<ll,int>z;
    for(int i=0;i<n;i++){
        z=heap.top();
        //agar ek bhi student nehin he
        if(price[z.second].size() ==0){
            price[z.second].push_back(monk[i]);
            z.first+=monk[i];
            ans[i]=z.second;//course number
            heap.pop();
            heap.push(z);
        }
        //agar ek student he
        else if(price[z.second].size() == 1) {
            z.first = (z.first+monk[i])*2;
            price[z.second].push_back(monk[i]);
            ans[i] = z.second;
            heap.pop();
            heap.push(z);
        }
        //agar do student he
        else if(price[z.second].size() >= 2) {
            int l = price[z.second].size();
            z.first = (price[z.second][l-1]+monk[i]);
            price[z.second].push_back(monk[i]);
            ans[i] = z.second;
            z.first *= (l+1);
            heap.pop();
            heap.push(z);
        }
    }
    for(int i = 0; i < n; i++) {
        cout<<ans[i]+1<<" ";
    }
    
    return 0;
}
