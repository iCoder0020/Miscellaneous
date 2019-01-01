/* 
Connected Components
{Kosaraju's Two Pass Algorithm} (for SCCs)
Time Complexity: O(N+M)
*/

#include <bits/stdc++.h>

using namespace std;

class Graph
{
	private:
		int V;
		int E;
		char type;
		vector <int> *adj_list;
		vector <int> *rev_adj_list;

		bool *visited_BFS;
		queue <int>Q;
		int WCC;
		
		bool *visited_DFS;
		stack <int>S;
		int *rev_sink_order;
		int order;
		int SCC;

	public:
		Graph(int V, char type)
		{
			this->V = V;
			this->E = 0;
			this->type = type; 
			this->adj_list = new vector<int>[V];
			this->rev_adj_list = new vector<int>[V];

			this->visited_BFS = new bool[V];
			for(int v = 0; v<V; v++)
			{
				visited_BFS[v] = false;
			}
			this->WCC = 0;

			this->visited_DFS = new bool[V];
			for(int v = 0; v<V; v++)
			{
				visited_DFS[v] = false;
			}
			this->rev_sink_order = new int[V];
			this->order = 0;
			this->SCC = 0;
		}

		void add_edge(int u, int v)
		{
			adj_list[u].push_back(v);
			rev_adj_list[v].push_back(u);
			E++;
		}

		void end_graph()
		{
			if(type == 'u')
			{
				for(int i = 0; i<V; i++)
				{
					for(int j = 0; j<adj_list[i].size(); j++)
					{
						this->add_edge(adj_list[i][j], i);
					}
				}
			}
			if(type == 'd')
			{

			}
		}

		void reset_BFS()
		{
			for(int v = 0; v<V; v++)
			{
				visited_BFS[v] = false;
			}
			this->WCC = 0;
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
						Q.push(adj_list[temp][n]);
					}
				}
			}
		}

		int calculate_WCC()
		{
			reset_BFS();
			for(int i = 0; i<V; i++)
			{
				if(visited_BFS[i] == false)
				{
					BFS(i);
					WCC++;
				}
			}
			return WCC;
		}

		void reset_DFS()
		{
			for(int v = 0; v<V; v++)
			{
				visited_DFS[v] = false;
			}
		}

		void DFS(int s, bool rev = false)
		{
			S.push(s);
			while(!S.empty())
			{
				int temp = S.top();
				S.pop();
				if(visited_DFS[temp] == false)
				{
					visited_DFS[temp] = true;
					if(rev)
					{
						for(int n = 0; n<rev_adj_list[temp].size(); n++)
						{
							DFS(rev_adj_list[temp][n], true);
						}
						rev_sink_order[order] = s;
						order++;
					}
					else
					{
						for(int n = 0; n<adj_list[temp].size(); n++)
						{
							DFS(adj_list[temp][n], false);
						}
					}
				}
			}
		}

		int calculate_SCC()
		{
			if(this->type == 'u')
			{
				return -1;
			}
			else
			{
				reset_DFS();
				for(int i = 0; i<V; i++)
				{
					if(visited_DFS[i] == false)
					{
						DFS(i, true);
					}
				}
				reset_DFS();
				for(int i = V-1; i>=0; i--)
				{
					if(visited_DFS[rev_sink_order[i]] == false)
					{
						DFS(rev_sink_order[i], false);
						SCC++;
					}
				}
				return SCC;
			}
		}
};


int main()
{
	int V;
	char type;
	cin>>V>>type;
	
	Graph g(V, type);
	
	int u,v;
	while(cin>>u>>v)
	{
		g.add_edge(u,v);
	}
	g.end_graph();

	cout<<g.calculate_WCC()<<endl;
	cout<<g.calculate_SCC()<<endl;

	return 0;
}