//Newman–Shanks–Williams prime (NSW prime)
#include <bits/stdc++.h>
using namespace std;
 

int nswp(int n)
{
    vector<int>(n + 1);
 
    dp[0] = dp[1] = 1;
 
    for (int i = 2; i <= n; i++)
        dp[i] = 2 * dp[i - 1] + dp[i - 2];
 
    return dp[n];
}
 
// Driver Program
int main()
{
    int n;
    cin>>n;
 
    cout << nswp(n) << endl;
    return 0;
}