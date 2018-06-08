#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        string a;
        getline(cin,a);
        string ne=a;
        reverse(a.begin(),a.end());
        if(!ne.compare(a) && a.size()%2==0)
            cout<<"YES EVEN"<<endl;
        else if(!ne.compare(a) && a.size()%2!=0)
            cout<<"YES ODD"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    return 0;
}
