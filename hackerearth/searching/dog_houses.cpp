#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
 
int main(){
 int n;
 cin >> n;
 const int INF = int(1e9);
 vi arr(n), sum(1024, 0), lo(1024, 1023), hi(1024, 0);
 int grid[1024][1024] = {};
 for (int i = 0; i < n; i++){
  cin >> arr[i];
  sum[arr[i]]++;
  lo[arr[i]] = min(lo[arr[i]], i);
  hi[arr[i]] = max(hi[arr[i]], i);
  grid[arr[i]][i] = 1;
 }
 for (int i = 0; i < 1024; i++){
  for (int j = 0; j < 1024; j++){
   if (i) grid[i][j] += grid[i-1][j];
   if (j) grid[i][j] += grid[i][j-1];
   if (i && j) grid[i][j] -= grid[i-1][j-1];
  }
 }
 int res = 0;
 
 for (int i = 0; i < 1024; i++){  
  for (int j = i + 1; j < 1024; j++){
   int cur = sum[i] + sum[j];
   int lo_cur = min(lo[i], lo[j]), hi_cur = max(hi[i], hi[j]);
   if (lo_cur) cur += min(1, grid[j][lo_cur - 1] - grid[i][lo_cur - 1]);
   if (n != 1) cur += min(1, grid[j][1023] - grid[i][1023] - grid[j][hi_cur] + grid[i][hi_cur]);
   res = max(res, cur);
  }
 }
 cout << res << "\n";
 return 0;
}
