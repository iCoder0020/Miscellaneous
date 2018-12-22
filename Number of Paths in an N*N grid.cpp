/* 
Number of Paths in an N*N grid

		example:

		s . . . . . .
		. . . . . . .
		. . . . . . .
		. . . . . . . 
		. . . . . . .
		. . . . . . .
		. . . . . . e

		ans = 111712

Time Complexity: 
*/

#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void count_ways(int x, int y, int N, vector <bool> visited[])
{
	cout<<x<<" "<<y<<endl;
	if(x<0 || x>=N || y<0 || y>=N || visited[x][y] == true)
	{
		return;
	}
	else
	{
		visited[x][y] = true;
	}
	if(x == N-1 && y == N-1)
	{
		bool all = true;
		for(int i = 0; i<N; i++)
		{
			for(int j = 0; j<N; j++)
			{
				if(visited[i][j] == false)
				{
					all = false;
					break;
				}
			}
			if(all == false)
			{
				break;
			}
		}
		if(all)
		{
			cout<<"Incremented at "<<x<<", "<<y<<endl;
			cnt++;
		}
	}
	else
	{
		count_ways(x+1,y,N,visited);
		count_ways(x,y+1,N,visited);
	}
}

int main()
{
	int N;
	cin>>N;
	vector <bool> visited[N];
	vector <bool> not_visited(N, false);
	for(int i = 0; i<N; i++)
	{
		visited[i] = not_visited;
	}
	count_ways(0, 0, N, visited);
	cout<<cnt<<endl;
	return 0;
}