/*
Sieve of Eratosthenes
Time Complexity: O(N*log(logN))
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int A[N-1];
	for(int i = 0; i<N-1; i++)
	{
		A[i] = i+2;
	}
	for(int i = 2; i<=N/2; i++)
	{
		for(int j = 2; i*j<=N; j++)
		{
			A[i*j-2] = 0;
		}
	}
	for(int i = 0; i<N-1; i++)
	{
		if(A[i] != 0)
		{
			cout<<A[i]<<" ";
		}
	}
	cout<<"\n";
	return 0;
}