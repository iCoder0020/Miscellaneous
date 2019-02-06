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

int total_visited = 0;
int cnt = 0;

vector<bool> visited[7];

void count_ways(int x, int y, int N)
{
	if(x<0 || x>=N || y<0 || y>=N || visited[x][y] == true)
	{
		return;
	}
	else
	{
		visited[x][y] = true;
		total_visited ++;
	}
	if(x == N-1 && y == N-1)
	{
		if(total_visited == N*N)
		{
			cnt++;
		}
		visited[x][y] = false;
		total_visited--;
		return;
	}
	else
	{		
		if((x-1>=0 && visited[x-1][y] == true) && (x+1<N && visited[x+1][y] == true) && (y-1<0 || visited[x][y-1] == false) && (y+1>=N || visited[x][y+1] == false))
		{
			visited[x][y] = false;
			total_visited--;
			return;
		}
		if((x-1<0 || visited[x-1][y] == false) && (x+1>=N || visited[x+1][y] == false) && (y-1>=0 && visited[x][y-1] == true) && (y+1<N && visited[x][y+1] == true))
		{
			visited[x][y] = false;
			total_visited--;
			return;
		}
		
		count_ways(x+1,y,N);
		count_ways(x,y+1,N);
		count_ways(x-1,y,N);
		count_ways(x,y-1,N);
		visited[x][y] = false;
		total_visited--;
	}
}

int main()
{
	int N;
	cin>>N;
	vector <bool> not_visited(N, false);
	for(int i = 0; i<N; i++)
	{
		visited[i] = not_visited;
	}
	visited[0][0] = true;
	total_visited = 1;
	count_ways(1, 0, N);
	cout<<cnt*2<<endl;
	return 0;
}