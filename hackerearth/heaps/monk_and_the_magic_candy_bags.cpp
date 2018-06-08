#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        priority_queue<ll>heap;
        for(int j=0;j<n;j++)
            {
                ll a;
                cin>>a;
                heap.push(a);
            }
            ll sum=0;
        for(int j=0;j<k;j++)
        {
            sum+=heap.top();
            double candy=floor(heap.top()/(2.0+0.0));
            heap.pop();
            ll pu=(ll)candy;
            heap.push(pu);
        }
        cout<<sum<<endl;
    }
    return 0;
}
