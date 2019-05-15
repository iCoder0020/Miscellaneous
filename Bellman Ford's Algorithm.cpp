/* 
Bellman Ford's Algorithm
(Undirected)
Time Complexity: O(EV)
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N,M;
    cin>>N>>M;
    int start;
    vector<pair<int,int>>adj[N+1];
    for(int m = 0; m<M; m++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin>>start;
    vector<int>dis(N+1, INT_MAX);

    dis[start] = 0;

    for(int i = 0; i<N-1; i++)
    {
        for(int u = 1; u<=N; u++)
        {
            for(auto it: adj[u])
            {
                int v = it.first;
                int w = it.second;

                dis[v] = min(dis[v], dis[u]+w);
            }
        }
    }

    for(int u = 1; u<=N; u++)
    {
        for(auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;

            if(dis[v] != min(dis[v], dis[u]+w))
            {
                cout<<"Negative cycle";
            }
        }
    }

    for(int i = 1; i<=N; i++)
    {
        if(i != start)
        {
            if(dis[i] == INT_MAX)
                cout<<-1<<" ";
            else
                cout<<dis[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}