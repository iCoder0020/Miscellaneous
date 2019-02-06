/*
Greedy Scheduling of Jobs
O(N*logN)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long double li;

bool mysort(pair<li, li> A, pair<li, li> B)
{
	li diff1 = (A.first - A.second) - (B.first - B.second);
	li diff2 = (A.first/A.second) - (B.first/B.second);
	if(diff1 > 0)
	{
		return true;
	}
	else if(diff1 == 0)
	{
		if(A.first > B.first)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int N;
	cin>>N;
	pair<li, li> A[N];
	li ans = 0;
	li total_time = 0;
	for(int n = 0; n<N; n++)
	{
		cin>>A[n].first>>A[n].second;
	}
	sort(A, A+N, mysort);
	for(int n = 0; n<N; n++)
	{
		total_time += A[n].second;
		ans += total_time*A[n].first;
	}
	cout<<(long long int)(ans)<<endl;
	return 0;
}

//69119377652
//67311454237