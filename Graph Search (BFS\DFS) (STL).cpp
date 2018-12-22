/* 
Graph Search(BFS\DFS)(STL)
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

		int *BFS_order;
		int order_BFS;
		bool *visited_BFS;
		queue <int>Q;
		
		int *DFS_order;
		int order_DFS;
		bool *visited_DFS;
		stack <int>S;

	public:
		Graph(int V, char type)
		{
			this->V = V;
			this->E = 0;
			this->type = type; 
			this->adj_list = new vector<int>[V];

			this->BFS_order = new int[V];
			this->order_BFS = 0;
			this->visited_BFS = new bool[V];
			for(int v = 0; v<V; v++)
			{
				visited_BFS[v] = false;
			}

			this->DFS_order = new int[V];
			this->order_DFS = 0;
			this->visited_DFS = new bool[V];
			for(int v = 0; v<V; v++)
			{
				visited_DFS[v] = false;
			}
		}

		void add_edge(int u, int v)
		{
			adj_list[u].push_back(v);
			E++;
		}

		void end_graph()
		{
			if(type == 'u')
			{
				E/=2;
			}
			if(type == 'd')
			{

			}
		}

		void info()
		{
			cout<<"No. of vertices: "<<V<<endl;
			cout<<"No. of edges: "<<E<<endl;
			cout<<"Type of graph: ";
			switch(type)
			{
				case 'd':
					cout<<"Directed";
					break;

				case 'u':
					cout<<"Undirected";
					break;

				default:
					cout<<"Unknown";
					break;
			}
			cout<<endl;
		}

		int return_vertices()
		{
			return V;
		}

		int return_edges()
		{
			return E;
		}

		void reset_BFS()
		{
			order_BFS = 0;
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
					BFS_order[order_BFS] = temp;
					order_BFS++;
					for(int n = 0; n<adj_list[temp].size(); n++)
					{
						Q.push(adj_list[temp][n]);
					}
				}
			}
		}

		void print_BFS_order()
		{
			for(int v = 0; v<V; v++)
			{
				cout<<BFS_order[v]<<" ";
			}
			cout<<endl;
		}

		void reset_DFS()
		{
			order_DFS = 0;
			for(int v = 0; v<V; v++)
			{
				visited_DFS[v] = false;
			}
		}

		void DFS(int s)
		{
			S.push(s);

			while(!S.empty())
			{
				int temp = S.top();
				S.pop();
				if(visited_DFS[temp] == false)
				{
					visited_DFS[temp] = true;
					DFS_order[order_DFS] = temp;
					order_DFS++;
					for(int n = 0; n<adj_list[temp].size(); n++)
					{
						DFS(adj_list[temp][n]);
					}
				}
			}
		}

		void print_DFS_order()
		{
			for(int v = 0; v<V; v++)
			{
				cout<<DFS_order[v]<<" ";
			}
			cout<<endl;
		}
};


int main()
{
	int V;
	cin>>V;
	
	Graph g(V, 'u');
	
	int u,v;
	while(cin>>u>>v)
	{
		g.add_edge(u,v);
	}
	g.end_graph();

	int starting_vertex;
	cin>>starting_vertex;
	
	g.reset_BFS();
	g.BFS(starting_vertex);
	g.print_BFS_order();

	g.reset_DFS();
	g.DFS(starting_vertex);
	g.print_DFS_order();

	return 0;
}