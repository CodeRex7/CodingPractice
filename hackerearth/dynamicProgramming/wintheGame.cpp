#include<bits/stdc++.h>
using namespace std;
double dp[1003][1003];

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int r,g;
        cin>>r>>g;
        for (int i = 0; i <=r; i++)
        {
        for (int j = 0; j <=g; j++)
        {
          if(i==0){ dp[i][j]=1; continue;}
          if(j==0){ dp[i][j]=1; continue;}
          dp[i][j]= i*1.0/(i+j)+ (j*1.0/(i+j))*((j-1)*1.0/(i+j-1))*dp[i][j-2];
        }
     }
     printf("%.6f\n",dp[r][g]);
  }
    return 0;
}