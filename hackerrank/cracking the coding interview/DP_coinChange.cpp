#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long int count( vector<long long int>S,long long int m,long long int n )
{
    
   vector<long long int>table(n+1);
 
  
    table[0] = 1;
 
    
    for(long long int i=0; i<m; i++)
    {
        for(long long int j=S[i]; j<=n; j++){
            table[j] += table[j-S[i]];
            
        }
     
    }
 
    return table[n];
}

int main()
{
    long long int m,n;
    cin>>m>>n;
    vector<long long int>a(n);
    for(long long int i=0;i<n;i++){
      cin>>a[i];  
    }
    cout<<count(a,n,m)<<endl;
}
