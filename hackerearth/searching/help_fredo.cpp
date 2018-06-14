#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int max=INT_MAX,min=0;
    double prod;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        prod+=log10(a);
    }
    /*prod=prod/(n+0.0);
    if((ll)ceil(pow(10,prod)) == (ll)pow(10,prod))
        cout<<(ll)ceil(pow(10,prod))+1<<endl;
    else    
        cout<<(ll)ceil(pow(10,prod))<<endl;*/
    while(min<=max){
        if(min==max)
            {
                cout<<min<<endl;
                break;
            }
        ll mid=min+(max-min)/2;
        if(n*log10(mid) > prod )
            {
                max=mid;
            }
        else
            {
                min=mid+1;
            }
    }    
    return 0;
}
