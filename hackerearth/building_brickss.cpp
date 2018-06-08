#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>fac(100001,0);
    for(int i=0;i<n;i++)
    {   
        cin>>a[i];
        for(int j=1;j<=sqrt(a[i]);j++){
            if(a[i]%j==0)
            {
                if(a[i]/j == j)
                    fac[j]++;
                else{
                    fac[j]++;
                    fac[a[i]/j]++;
                }
            }
        }
    }
    int b;
    cin>>b;
    for(int i=0;i<b;i++){
        int k;
        cin>>k;
        cout<<fac[k]<<endl;
        }
    return 0;
}
