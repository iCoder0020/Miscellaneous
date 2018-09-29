/*
Matrix Multiplication
Time Complexity: O(N^2*M)
*/

#include <iostream>

using namespace std;

int main()
{
	int N,M;
	int Z_element;
	cin>>N>>M;
	int X[N][M], Y[M][N], Z[N][N];
	cout<<"\n";
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<M; j++)
		{
			cin>>X[i][j];
		}
	}
	cout<<"\n";
	for(int i = 0; i<M; i++)
	{
		for(int j = 0; j<N; j++)
		{
			cin>>Y[i][j];
		}
	}
	cout<<"\n";
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			Z_element = 0;
			for(int k = 0; k<M; k++)
			{
				Z_element += X[i][k]*Y[k][j]; 
			}
			Z[i][j] = Z_element;
		}

	}
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			cout<<Z[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}