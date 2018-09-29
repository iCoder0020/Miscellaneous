/*
Merge Sort
Time Complexity: O(N*logn)
*/

#include <iostream>

using namespace std;

void merge(int A[], int l, int m, int r)
{
	int B[m-l], C[r-m];
	for(int i = l; i<m; i++)
	{
		B[i-l] = A[i];
	}
	for(int i = m; i<r; i++)
	{
		C[i-m] = A[i];
	}
	int i = 0, j = 0;
	for(int k = l; k<r; k++)
	{
		if(i == m-l)
		{
			for(j; j<r-m; j++)
			{
				A[k] = C[j];
				k++;
			}
			break;
		}
		if(j == r-m)
		{
			for(i; i<m-l; i++)
			{
				A[k] = B[i];
				k++;
			}
			break;
		}
		if(B[i]<C[j])
		{
			A[k] = B[i];
			i++;
		}
		else
		{
			A[k] = C[j];
			j++;
		}
	}
}

void merge_sort(int A[], int l, int r)
{
	int m = (l+r)/2 + (l+r)%2;	//dividing the array into two parts
    if(m != r)	//end condition for the recursive loop
    {
        merge_sort(A, l, m);	//first part of array [0 - N/2)
        merge_sort(A, m, r);	//second part of array [N/2 - N)

        merge(A, l, m, r);	//merges two arrays (arranged in ascending order) in ascending order
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
	merge_sort(A, 0, N);
    for(int i = 0; i<N; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
	return 0;
}