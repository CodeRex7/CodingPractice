    #include <bits/stdc++.h>
    using namespace std;
    int main () {
    	int n;
    	cin >> n;
    	vector < int > v;
    	v.resize(n);
    	for (int i=0; i<n; i++) cin >> v[i];
    	sort(v.begin(),v.end());
    	int q;
    	cin >> q;
    	while (q--) {
    		int k; char c;
    		cin >> k >> c;
    		if ( c == 'S' )
    			cout << v[k-1] << endl;
    		else
    			cout << v[n-k] << endl;
    	}
    	return 0;
    }
