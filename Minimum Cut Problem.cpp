/* 
Minimum Cut Problem
Time Complexity: O(N^6)
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int min(int a, int b)
{
	return (a<b)?a:b;
}

int join_random_vertices(vector <int> *adj_list, int vertices_left)
{
	if(vertices_left == 2)
	{
		return adj_list[0].size();
	}
	else
	{
		vector <int> new_adj_list[vertices_left-1];
		srand(time(NULL));
		int v1 = rand()%vertices_left;
		int v1_random_vertice = rand()%adj_list[v1].size();
		int v2 = adj_list[v1][v1_random_vertice];
		int new_count = 0;
		int m;
		for(int k = 0; k<vertices_left; k++)
		{
			if(k!=v1 && k!=v2)
			{
				for(int l = 0; l<adj_list[k].size(); l++)
				{
					if(adj_list[k][l] == v1 || adj_list[k][l] == v2)
					{
						new_adj_list[new_count].push_back(vertices_left-2);
					}
					else
					{
						m = 0;
						if(adj_list[k][l] > v1)
						{
							m++;
						}
						if(adj_list[k][l] > v2)
						{
							m++;
						}
						m = adj_list[k][l] - m; 
						new_adj_list[new_count].push_back(m);
					}
				}
				new_count++;
			}	
		}

		for(int l = 0; l<adj_list[v1].size(); l++)
		{
			if(adj_list[v1][l] != v2)
			{
				m = 0;
				if(adj_list[v1][l] > v1)
				{
					m++;
				}
				if(adj_list[v1][l] > v2)
				{
					m++;
				}
				m = adj_list[v1][l] - m; 
				new_adj_list[vertices_left-2].push_back(m);
			}
		}

		for(int l = 0; l<adj_list[v2].size(); l++)
		{
			if(adj_list[v2][l] != v1)
			{
				m = 0;
				if(adj_list[v2][l] > v1)
				{
					m++;
				}
				if(adj_list[v2][l] > v2)
				{
					m++;
				}
				m = adj_list[v2][l] - m; 
				new_adj_list[vertices_left-2].push_back(m);
			}
		}
		return join_random_vertices(new_adj_list, vertices_left-1);
	}
}

int main()
{
	int N;
	cin>>N;
	vector <int> adj_list[N];
	int m;
	char c;
	int cuts,min_cuts=0;
	for(int n = 0; n<N; n++)
	{
		scanf("%d%c", &m, &c);
		while(1)
		{
			scanf("%d%c", &m, &c);
			adj_list[n].push_back(m-1);
			if(c == '\n')
			{
				break;
			}
		}
	}


	for(int n = 0; n<5*N; n++)
	{
		cuts = join_random_vertices(adj_list, N);
		if(min_cuts == 0)
		{
			min_cuts = cuts;
		}
		else
		{
			min_cuts = min(min_cuts, cuts);
		}
	}
	cout<<min_cuts<<"\n";
	return 0;
}