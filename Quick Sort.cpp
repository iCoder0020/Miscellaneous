/*
Quick Sort
Time Complexity: O(N*logN)
*/

#include <iostream>

using namespace std;

void swap(int A[], int i, int j)
{
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int find_pivot(int A[], int l, int r)
{
	//Pivot is the median of three elements
	
	int a = l;
	int b;
	if((r-l)%2 == 0)
	{
		b = (r+l)/2 - 1;
	} 
	else
	{
		b = (r+l)/2;
	}
	int c = r-1;
	
	if((A[a]>=A[b] && A[a]<=A[c]) || (A[a]<=A[b] && A[a]>=A[c]))
	{
		return a;
	}
	else if((A[a]>=A[b] && A[b]>=A[c]) || (A[a]<=A[b] && A[b]<=A[c]))
	{
		return b;
	}
	else
	{
		return c;
	}

	//Pivot is the first element of the subarray
	/*
	return l;
	*/

	//Pivot is the last elemeny of the subarray
	/*
	return r-1;
	*/
}

int quick_sort(int A[], int l, int r, int p)
{
	int i,j;
	i = l+1;
	j = l+1;
	for(j; j<r; j++)	
	{
		if(A[j]<A[p])
		{
			swap(A, i, j);
			i++;
		}
	}
	swap(A, i-1, p);
	return i-1;
}

void divide_and_sort(int A[], int l, int r)
{
	int pivot = find_pivot(A,l,r);
	swap(A, l, pivot);
	int next = quick_sort(A, l, r, l);
	if(next-1>l)
	{
		divide_and_sort(A, l, next);	
	}
	if(r-1>next+1)
	{
		divide_and_sort(A, next+1, r);
	}
}

int main()
{
	int N;
	cin>>N;
	int A[N];
	for(int i = 0; i<N; i++)
	{
		cin>>A[i];
	}
	divide_and_sort(A, 0, N);
	for(int i = 0; i<N; i++)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}