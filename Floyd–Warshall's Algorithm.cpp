/* 
Floyd–Warshall's Algorithm
(Undirected)
Time Complexity: O(V^3)
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
    int dis[N+1][N+1];

    for(int i = 0; i<=N; i++)
    {
        for(int j = 0; j<=N; j++)
        {
            if(i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INT_MAX;
        }
    }

    for(int m = 0; m<M; m++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = dis[u][v];
    }

    for(int k = 1; k<=N; k++)
    {
        for(int i = 1; i<=N; i++)
        {
            for(int j = 1; j<=N; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}