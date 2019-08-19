/*
Prim's MST Algorithm
Time Complexity: O(ElogV)
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
    map<pair<int,int>,int>MAP;
    for(int m = 0; m<M; m++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(MAP.find({u,v}) == MAP.end())
        	MAP[{u,v}] = w;
        else
        	MAP[{u,v}] = min(MAP[{u,v}], w);
    }
    for(auto it: MAP)
    {
    	int u = it.first.first;
    	int v = it.first.second;
    	int w = it.second;

    	adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cin>>start;

    vector<bool>vis(N+1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});

    int sum = 0;

    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        int u = temp.second;
        int d = temp.first;
        if(!vis[u])
        {
            sum += d;
            vis[u] = true;

            for(auto it: adj[u])
            {
                int v = it.first;
                int w = it.second;

                if(vis[v] == false)
                    pq.push({w, v});
            }
        }
    }

    cout<<sum<<endl;
    return 0;
}