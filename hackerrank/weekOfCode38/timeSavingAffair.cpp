#include <bits/stdc++.h>
#define mp make_pair
using namespace std;


int leastTimeToInterview(int n, int k, int m) {
    set< pair<int,int> >set;
    vector<int>dist(n, INT_MAX);
    //vector<int>red(n);
    list< pair<int, int> > *adj;
    adj = new list< pair<int, int> >[n];
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a-1].push_back(make_pair(b-1, c));
        adj[b-1].push_back(make_pair(a-1, c));
    }
    set.insert(make_pair(0,0));
    dist[0]=0;
    
    while (!set.empty())
    {
        pair<int, int> tmp = *(set.begin());
        set.erase(set.begin());
 
        int u = tmp.second;
        
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = i->first;
            int weight = i->second;
            int temp=dist[u]+weight;
            int add=0;
            if(((temp)/k)%2!=0)
                add=k-(temp%k);                                    
            if (dist[v] > dist[u] + weight + add)
            {
                if (dist[v] != INT_MAX)
                    set.erase(set.find(make_pair(dist[v], v)));
 
                dist[v] = dist[u] + weight;
                if(((dist[v])/k)%2!=0 && v!=(n-1))
                    {
                        dist[v]+=(k-(dist[v]%k));
                        //cout<<v+1<<endl;
                    }
                set.insert(make_pair(dist[v], v));
            }
            //cout<<dist[u]<<" "<<dist[v]<<" "<<v+1<<endl;
        }
    }
    return dist[n-1];
}

int main()
{
    int n,k,m;
    cin>>n>>k>>m;

    int result = leastTimeToInterview(n, k, m);

    cout<<result<<endl;
    return 0;
}
