#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    vector<int> police,thief;      
    int i,j,n,t,k,cnt=0;
    unsigned int p_i,t_i;
    char ch;
    cin>>t;                       
    while(t--)
    {
        cnt=0;
        police.clear();        
        thief.clear();
        cin>>n>>k;
 
        for(i=0;i<n;i++)
        {
            police.clear();
            thief.clear();
 
            for(j=0;j<n;j++)
            {
                cin>>ch;
                if(ch=='P')
                    police.push_back(j);   
               else         
                    thief.push_back(j);   
 
            }
            t_i=0;p_i=0;
            while(t_i<thief.size()&&p_i<police.size()) 
            {
                if(abs(police[p_i]-thief[t_i])<=k)
 
                    {
                        cnt++;t_i++;p_i++;         
                    }
                else if(police[p_i]>thief[t_i]) 
                   {
                       t_i++;
                   }
                else
                   {
                        p_i++;
                   }
            }
        }
        cout<<cnt<<endl;        
 
    }
    return 0;
}
