/*
Kruskal's MST Algorithm
Time Complexity: O(ElogV)
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int>rep;
vector<int>sz;

void make_set(int x)
{
    rep[x] = x;
    sz[x] = 1;
}

int find_set(int x)
{
    while(rep[x] != x)
    {
        rep[x] = rep[rep[x]];
        x = rep[x];
    }
    return x;
}

void union_set(int x, int y)
{
    int a = find_set(x);
    int b = find_set(y);

    if(a!=b)
    {
        if(sz[a] < sz[b])
        {
            rep[b] = a;
            sz[a] += sz[b];
        }
        else
        {
            rep[a] = b;
            sz[b] += sz[a];
        }
    }
}


bool mysort(pair<pair<int,int>,int> &A, pair<pair<int,int>,int> &B)
{
    return A.second<B.second;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int N,M;
    cin>>N>>M;
    vector<pair<pair<int,int>,int>> edges;
    map<pair<int,int>,int>MAP;
    rep.resize(N+1);
    sz.resize(N+1);
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

    	edges.push_back({{u,v},w});
    }

    for(int n = 0; n<=N; n++)
        make_set(n);

    sort(edges.begin(), edges.end(), mysort);

    int sum = 0;

    for(auto it: edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;

        if(find_set(u) != find_set(v))
        {
            sum += w;
            union_set(u,v);
        }
    }

    cout<<sum<<endl;

    return 0;
}