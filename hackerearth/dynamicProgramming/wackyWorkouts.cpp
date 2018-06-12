#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007LL
ll result[2][2];
void mul(ll m1[2][2], ll m2[2][2]) {
	result[0][0] = (m1[0][0]*m2[0][0]+m1[0][1]*m2[1][0])%MOD;
	result[0][1] = (m1[0][0]*m2[0][1]+m1[0][1]*m2[1][1])%MOD;
	result[1][0] = (m1[1][0]*m2[0][0]+m1[1][1]*m2[1][0])%MOD;
	result[1][1] = (m1[1][0]*m2[0][1]+m1[1][1]*m2[1][1])%MOD;
}
 
ll cur[2][2];
void power(ll m[2][2], ll n) {
	if(n == 0) {
		cur[0][0] = 1;	cur[1][0] = 1;
		cur[0][1] = 1;	cur[1][1] = 1;
		return;
	} else if(n == 1) {
		cur[0][0] = m[0][0];	cur[1][0] = m[1][0];
		cur[0][1] = m[0][1];	cur[1][1] = m[1][1];
		return;
	}
 
	if(n % 2) {
		power(m, n/2);
		mul(cur, cur);
		cur[0][0] = result[0][0];	cur[1][0] = result[1][0];
		cur[0][1] = result[0][1];	cur[1][1] = result[1][1];
 
		mul(cur, m);
		cur[0][0] = result[0][0];	cur[1][0] = result[1][0];
		cur[0][1] = result[0][1];	cur[1][1] = result[1][1];
	} else {
		power(m, n/2);
		mul(cur, cur);
		cur[0][0] = result[0][0];	cur[1][0] = result[1][0];
		cur[0][1] = result[0][1];	cur[1][1] = result[1][1];
	}
}
 
int main(void) {
	int T; cin >> T;
	while(T--) {
		ll n; cin >> n;
		ll m[2][2] = {{1, 1}, {1, 0}}; 
		power(m, n+1);
		cout << cur[0][0] << '\n';
	}
}