#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<char>a(2050);
    vector<int>cnt(26);
    ll ans=0;
    for (int i = 1;i <= n;i++) {
    cin >> a[i];
    }
    for (int i = 1;i <= n;i++)
    {
        ll now = 0;
        for (int j = i + 1;j <= n;j++)
        {
            if (a[j] == a[i])
            {
                ans += now;
            }
            now += cnt[a[j] - 'a'];
            //cout<<ans<<"    "<<now<<endl;
        }
        //cout<<"jhgf"<<endl;
        cnt[a[i] - 'a']++;
     }
    cout << ans << endl;
    return 0;
}