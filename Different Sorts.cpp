#include <bits/stdc++.h>

using namespace std;

void print(vector<int> A)
{
	for(auto it: A)
	{
		cout<<it<<" ";
	}
	cout<<endl;
}

void swap(vector<int>&A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void selection_sort(vector<int> A, int N)
{
	for(int i = 0; i<N-1; i++)
	{
		for(int j = i+1; j<N; j++)
		{
			if(A[i] > A[j])
			{
				swap(A, i, j);
			}
		}
	}
	print(A);
}

void bubble_sort(vector<int> A, int N)
{
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N-i-1; j++)
		{
			if(A[j] > A[j+1])
			{
				swap(A, j, j+1);
			}
		}
	}
	print(A);
}

void insertion_sort(vector<int> A, int N)
{
	for(int i = 0; i<N; i++)
	{
		int key = A[i];
		int j = i-1;
		while(j>=0 && A[j] > key)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
	print(A);
}

void merge_main(vector<int> &A, int l, int m, int r)
{
	int a = m-l;
	int b = r-m;

	int arr1[a];
	int arr2[b];
	int arr3[a+b];

	for(int n = l; n<m; n++)
	{
		arr1[n-l] = A[n];
	}
	for(int n = m; n<r; n++)
	{
		arr2[n-m] = A[n];
	}

	int i = 0;
	int j = 0;
	int k = 0;

	while(1)
	{
		if(i == a)
		{
			while(j!=b)
			{
				arr3[k] = arr2[j];
				j++;
				k++;
			}
			break;
		}
		else if(j == b)
		{
			while(i!=a)
			{
				arr3[k] = arr1[i];
				i++;
				k++;
			}
		}
		else
		{
			if(arr1[i] < arr2[j])
			{
				arr3[k] = arr1[i];
				i++;
			}
			else
			{
				arr3[k] = arr2[j];
				j++;
			}
			k++;
		}
	}

	for(int n = l; n<r; n++)
	{
		A[n] = arr3[n-l];
	}
}

void merge_rec(vector<int> &A, int l, int r)
{
	if(r-l <= 1)
	{
		return;
	}
	else
	{
		int m = (l+r)/2 + (r-l)%2;
		merge_rec(A, l, m);
		merge_rec(A, m, r);
		merge_main(A, l, m, r);
	}
}

void merge_sort(vector<int> A, int N)
{	
	merge_rec(A, 0, N);
	print(A);
}

int find_pivot(vector<int>A, int l, int r)
{
	srand(time(NULL));
	int pivot = l + rand()%(r-l);

	return pivot;
}

int quick_main(vector<int> &A, int l, int r)
{
	int p = find_pivot(A,l,r);

	int i;
	int key = A[p];

	swap(A, p, l);

	i = l-1;

	for(int index = l+1; index<r; index++)
	{
		if(A[index] < key)
		{
			i++;
			swap(A, index, i+1);
		}
	}
	swap(A, i+1, l);
	return i+1;
}


void quick_rec(vector<int>&A, int l, int r)
{
	if(l >= r)
	{
		return;
	}
	else
	{
		int m = quick_main(A, l, r);
		quick_rec(A, l, m);
		quick_rec(A, m+1, r);
	}
}

void quick_sort(vector<int> A, int N)
{
	quick_rec(A, 0, N);
	print(A);
}

void counting_sort1(vector<int> A, int N)
{
	map<int,int>M;
	for(int n = 0; n<N; n++)
	{
		auto it = M.find(A[n]);
		if(it == M.end())
		{
			M[A[n]] = 1;
		}
		else
		{
			M[A[n]]++;
		}
	}
	A.clear();
	for(auto it: M)
	{
		for(int n = 0; n<it.second; n++)
		{
			A.push_back(it.first);
		}
	}
	print(A);
}

void counting_sort2(vector<int> A, int N, int range_low, int range_max)
{
	int range = range_max - range_low + 1;
	vector<int> B(N, 0);
	vector<int> C(range, 0);
	for(int n = 0; n<N; n++)
	{
		C[A[n]+range_max]++;
	}
	for(int n = 1; n<range; n++)
	{
		C[n] += C[n-1];
	}
	for(int n = N-1; n>=0; n--)
	{
		B[C[A[n]+range_max]-1] = A[n];
		C[A[n]+range_max]--;
	}
	print(B);
}

int main() 
{
    vector<int> A = {1, 6, 78, -5, 0, -69, 10, 8, -7, 42, 0};
    int N = A.size();

    print(A);

    selection_sort(A, N);
    bubble_sort(A, N);
    insertion_sort(A, N);
    merge_sort(A, N);
    quick_sort(A, N);
    counting_sort1(A, N);
    counting_sort2(A, N, -1e5, 1e5);
    
    return 0;
}