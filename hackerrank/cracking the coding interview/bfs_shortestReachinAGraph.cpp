
#include<bits/stdc++.h>
using namespace std;


int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
            vector< vector<int> >ar(n);
            for( int i=0;i<n;i++){
                ar[i].resize(n);
            }
            for( int i=0;i<n;i++){
                for( int j=0;j<n;j++){
                    ar[i][j]=-1;
                }   
            }
            for( int i=0;i<n;i++){
                ar[i][i]=0;
            }
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            ar[u][v]=6;
            ar[v][u]=6;
        }
		int start;
        cin >> start;
        start--;
        // Find shortest reach from node s
        vector<int> dist(n,-1);
            /*for(int i=0;i<n;i++)
            {
                if(ar[start][i]>=0)
                {
                    if(dist[i]>ar[start][i])
                    {
                        dist[i]=ar[start][i];
                    }
                    for(int j=0;j<n;j++)
                    {
                        if(dist[j]>ar[i][j]+dist[i] && ar[i][j]>=0){dist[j]=dist[i]+ar[i][j];}
                    }
                }
                
            }*/
            queue <int> g;
            g.push(start);
            dist[start] = 0;
            while(!g.empty())
            {
                int v=g.front();
                g.pop();
                for(int i =0;i<n;i++)
                {
                    if(ar[v][i] == 6 && 
                    	dist[i] == -1 )
                    {
                        g.push(i);
                        dist[i] = dist[v]+ar[v][i];
                    }
                }
            }

        for (int i = 0; i < dist.size(); i++) {
            if (i != start) {
                cout << dist[i] << " ";
                
            }
            
        }
        cout << endl;
    }
    
    return 0;
}