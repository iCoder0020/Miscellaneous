/*
Matrix Exponentiation
Time Complexity: O(K^3*logN)
*/

#include <iostream>

using namespace std;

#define K 2
#define MOD 1000000007

typedef long long int ll;
typedef ll matrix[K][K];

matrix M = {{1,1},{1,0}};

void mul(matrix A, matrix B, matrix C)
{
	for(int i = 0; i<K; i++)
	{
		for(int j = 0; j<K; j++)
		{
			C[i][j] = 0;
		}
	}
	for(int i = 0; i<K; i++)
	{
		for(int j = 0; j<K; j++)
		{
			for(int k = 0; k<K; k++)
			{
				C[i][j] = ((C[i][j]%MOD) + ((A[i][k])%MOD*(B[k][j])%MOD)%MOD)%MOD;
			}
		}
	}
}

void assign(matrix A, matrix B)
{
	for(int i = 0; i<K; i++)
	{
		for(int j = 0; j<K; j++)
		{
			B[i][j] = A[i][j];
		}
	}
}

void power(matrix A, ll p, matrix ans)
{
	if(p == 1)
	{
		assign(A, ans);
	}
	else
	{
		if(p%2 == 1)
		{
			matrix temp;
			power(A, p-1, temp);
			mul(temp, M, ans);
		}
		else
		{
			matrix temp;
			power(A, p/2, temp);
			mul(temp, temp, ans);
		}
	}
}

int main()
{
	int N; 
	cin>>N;
	matrix ans;
	power(M, N, ans);
	for(int i = 0; i<K; i++)
	{
		for(int j = 0; j<K; j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}