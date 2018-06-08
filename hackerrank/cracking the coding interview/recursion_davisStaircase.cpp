#include <bits/stdc++.h>

using namespace std;


int main()
{
    vector<int>a(37);
    a[1]=1;
    a[2]=2;
    a[3]=4;
    for(int i=4;i<37;i++){
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        long long int n;
        cin >> n;
        
        cout<<a[n]<<endl;
    }

    return 0;
}
