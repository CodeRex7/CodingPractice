#include <bits/stdc++.h>

using namespace std;





int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int>map(100);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        map[a[i]]++;
    }
    int x=0;
    for(int i=0;i<100;i++){
        if(map[i]==1)
        {
            x=i;
            break;
        }
    }
    cout<<x<<endl;
    
    return 0;
}
