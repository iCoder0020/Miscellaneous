#include <bits/stdc++.h>

using namespace std;

long long int cnt = 0;

void print(int A[], int l, int r)
{
	for(int n = l; n<r; n++)
	{
		cout<<A[n]<<" ";
	}
	cout<<endl;
}

void merge(int A[], int l, int m, int r)
{
    long long int b = m-l;
    long long int c = r-m;
    int B[b];
    int C[c];

    for(int n = 0; n<b; n++)
    {
    	B[n] = A[n+l];
    }

    for(int n = 0; n<c; n++)
    {
    	C[n] = A[n+m];
    }

    int i,j,k;
    i = 0;
    j = 0;
    k = l;

    while(1)
    {
        if(i == b)
        {
            while(j!=c)
            {
                A[k] = C[j];
                j++;
                k++;
            }
            break;
        }
        else if(j == c)
        {
            while(i!=b)
            {
                A[k] = B[i];
                i++;
                k++;
            }
            break;
        }
        else
        {
            if(B[i] <= C[j])
            {
                A[k] = B[i];
                i++;
            }
            else
            {
                A[k] = C[j];
                j++;
                cnt += b-i;
            }
            k++;
        }
    }
}

void merge_sort(int A[], int l, int r)
{
    if(r-l<=1)
    {
        return;
    }
    else
    {
        int m = (l+r)/2 + (r-l)%2;
        merge_sort(A, l, m);
        merge_sort(A, m, r);
        merge(A, l, m, r);
    }
}

int main()
{
    int N;
    cin>>N;
    int A[N];
    for(int n = 0; n<N; n++)
    {
        cin>>A[n];
    }
    merge_sort(A, 0, N);
   	cout<<cnt<<endl;
    return 0;
}
