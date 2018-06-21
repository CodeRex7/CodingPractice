#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int main()
{
    int n;
    cin>>n;
    list< pair<int, int> > *adj;
    adj = new list< pair<int, int> >[n];
    for(int i=0;i<n;i++)
    {
        int w;
        cin>>w;
        adj[i].push_back(make_pair((i+1)%n, w));
    }
    int q;
    cin>>q;
    while(q--){
        int query;
        cin>>query;
        if(query==1){
            int a;
            int wt;
            cin>>a>>wt;
            set< pair<int,int> >set;
            vector<int>dist(n, INT_MAX);
            set.insert(make_pair(0,a));
            dist[a]=0;

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
                    if (dist[v] > dist[u] + weight && v!=a)
                    {
                        if (dist[v] != INT_MAX)
                            set.erase(set.find(make_pair(dist[v], v)));

                        dist[v] = dist[u] + weight;
                        set.insert(make_pair(dist[v], v));
                    }
                    //cout<<dist[u]<<" "<<dist[v]<<" "<<v+1<<endl;
                }
            }
            int max=0,pos_max=0;
            for(int i=0;i<n;i++){
                if(max<dist[i]){
                    max=dist[i];
                    pos_max=i;
                }
            }
            adj[pos_max].push_back(make_pair(n++, wt));  
        }else if(query==2){
            int a;
            int wt;
            cin>>a>>wt;
            adj[a].push_back(make_pair(n++, wt)); 
        }else if(query==3){
            int a;
            cin>>a;
            set< pair<int,int> >set;
            vector<int>dist(n, INT_MAX);
            set.insert(make_pair(0,a));
            dist[a]=0;

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
                    if (dist[v] > dist[u] + weight && v!=a)
                    {
                        if (dist[v] != INT_MAX)
                            set.erase(set.find(make_pair(dist[v], v)));

                        dist[v] = dist[u] + weight;
                        set.insert(make_pair(dist[v], v));
                    }
                    //cout<<dist[u]<<" "<<dist[v]<<" "<<v+1<<endl;
                }
            }
            int max=0,pos_max=0;
            for(int i=0;i<n;i++){
                if(max<dist[i]){
                    max=dist[i];
                    pos_max=i;
                }
            }
            //adj[pos_max]=INT_MAX;
        }else{
            int a;
            cin>>a;
            set< pair<int,int> >set;
            vector<int>dist(n, INT_MAX);
            set.insert(make_pair(0,a));
            dist[a]=0;

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
                    if (dist[v] > dist[u] + weight && v!=a)
                    {
                        if (dist[v] != INT_MAX)
                            set.erase(set.find(make_pair(dist[v], v)));

                        dist[v] = dist[u] + weight;
                        set.insert(make_pair(dist[v], v));
                    }
                    //cout<<dist[u]<<" "<<dist[v]<<" "<<v+1<<endl;
                }
            }
            int max=0,pos_max=0;
            for(int i=0;i<n;i++){
                if(max<dist[i]){
                    max=dist[i];
                    pos_max=i;
                }
            }
            cout<<max<<endl;
        }
    }
    return 0;
}