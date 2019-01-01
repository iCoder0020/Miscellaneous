/*
Topological Sort
Time Complexity: O(M+N)
*/

#include <bits/stdc++.h>

using namespace std;

class Graph
{
	private:
		int V;
		vector <int> *adj_list;
		
		bool *visited_DFS;
		stack <int>S;

		int current_label;
		int *topological_ordering;

	public:
		Graph(int V)
		{
			this->V = V;
			this->adj_list = new vector<int>[V];

			this->visited_DFS = new bool[V];
			for(int v = 0; v<V; v++)
			{
				visited_DFS[v] = false;
			}

			this->topological_ordering = new int[V];
		}

		void add_edge(int u, int v)
		{
			adj_list[u].push_back(v);
		}

		void reset_DFS()
		{
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
					for(int n = 0; n<adj_list[temp].size(); n++)
					{
						DFS(adj_list[temp][n]);
					}

					topological_ordering[current_label] = s;
					current_label--;
				}
			}
		}

		void topological_sort()
		{
			reset_DFS();
			current_label = V-1;
			for(int i = 0; i<V; i++)
			{
				if(visited_DFS[i] == false)
				{
					DFS(i);
				}
			}
		}

		void print_topological_ordering()
		{
			cout<<"The topological ordering is: "<<endl;
			for(int i = 0; i<V; i++)
			{
				cout<<topological_ordering[i];
				if(i != V-1)
				{
					cout<<"->";
				}
				else
				{
					cout<<endl;
				}
			}
		}
};

int main()
{
	int V;
	cin>>V;
	
	Graph g(V);
	
	int u,v;
	while(cin>>u>>v)
	{
		g.add_edge(u,v);
	}

	g.topological_sort();
	g.print_topological_ordering();

	return 0;
}