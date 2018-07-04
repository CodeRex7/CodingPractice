#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int i=0,j=s.size();
        int sum=0;
        vector<int>ar(26,0);
        int count=0;
        for(i=0;i<j;i++)
        {
            if(ar[s[i]-'a']==0)
                {ar[s[i]-'a']++;sum++;}
            else
                {ar[s[i]-'a']--;sum--;}
        }
        //cout<<sum<<" "<<j<<endl;
        if(j%2==0 && sum >0)
            cout<<"No"<<endl;
        else if(j%2!=0 && sum>1)
            cout<<"No"<<endl;
        else{    
            i=0;j=s.size()-1;
            while(i<j){
                if(s[i]!=s[j])
                    count++;
                i++;
                j--;
            }
        
        if(count<=2 && j+1>=5)
            cout<<"Yes"<<endl;
        else if(count<2 && j+1<5)
            cout<<"Yes"<<endl;
        else    
            cout<<"No"<<endl;
        }
    }
    return 0;
}