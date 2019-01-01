/* 
Shortest Distance (Weighted Undirected Graph)
{Dijkstra's Shortest Path Algorithm}
Time Complexity: O(N^2*log(N))
*/

#include <bits/stdc++.h>

using namespace std;

int min(int a, int b)
{
	return (a<b)?a:b;
}

class Graph
{
	private:
		int V;
		vector <int> *adj_list;

		bool *visited_BFS;
		queue <int>Q;

	public:
		Graph(int V)
		{
			this->V = V;
			this->adj_list = new vector<pair<int,int>>[V];

			this->visited_BFS = new bool[V];
			for(int v = 0; v<V; v++)
			{
				visited_BFS[v] = false;
			}
		}

		void add_edge(int u, int v, int w)
		{
			adj_list[u].push_back(make_pair(v,w));
		}

		void reset_BFS()
		{
			for(int v = 0; v<V; v++)
			{
				visited_BFS[v] = false;
			}
		}

		void BFS(int s)
		{
			Q.push(s);

			while(!Q.empty())
			{
				int temp = Q.front();
				Q.pop();
				if(visited_BFS[temp] == false)
				{
					visited_BFS[temp] = true;
					for(int n = 0; n<adj_list[temp].size(); n++)
					{
						Q.push(adj_list[temp][n].first);
					}
				}
			}
		}
};


int main()
{
	int V;
	cin>>V;
	
	Graph g(V);
	
	int u,v,w;
	while(cin>>u>>v>>w)
	{
		g.add_edge(u,v,w);
	}

	return 0;
}