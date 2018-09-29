/*
Searching the maximum element in a Unimodular Array
Time Complexity: O(logN)
*/

#include <iostream>
 
using namespace std;
 
int main()
{
	int A[] = {1,2,3,7,8,15,21,0};
	int N = sizeof(A)/sizeof(int);
	int min, mid, max;
	min = 0;
	max = N - 1;
	int count = 0;
	while(1)
	{
		count++;
		mid = (min+max)/2;
		if(mid>0 && mid<N-1 && A[mid-1]<A[mid] && A[mid]>A[mid+1])
		{
			cout<<A[mid]<<"\n";
			break;
		}
		else if(mid>0 && A[mid-1]<A[mid] && A[mid]<A[mid+1])
		{
			min = mid + 1;
		}
		else if(mid<N-1 && A[mid-1]>A[mid] && A[mid]>A[mid+1])
		{
			max = mid - 1;
		}
	}
	return 0;
}