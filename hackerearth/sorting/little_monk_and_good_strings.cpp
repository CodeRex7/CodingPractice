#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    getline(cin,s);
    int max=0,count=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            count++;
        else
            {
                if(max<=count)
                    max=count;
            count=0;
            }
    }
    if(max<=count)
        max=count;
    cout<<max<<endl;
    return 0;
}
