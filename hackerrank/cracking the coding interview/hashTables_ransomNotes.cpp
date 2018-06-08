#define ll long long int
#include<bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    map<string, int> map;
    string s;

    cin >> m >> n;

    
    for (int i = 0; i < m; ++i)
        {
       cin >> s;
       map[s]++; 
    }
    int k;
    
    for (int j = 0; j < n; ++j) {
        cin >> s;
       map[s]=map[s]-1;
        
        if ( map[s] < 0)
            { 
            cout << "No" << endl;
            return 0;
        }
    }
    
    cout << "Yes" << endl;
    return 0;
}
