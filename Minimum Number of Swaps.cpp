#include <bits/stdc++.h>

using namespace std;

int min_swaps(vector<int> A)
{
	int N = A.size();
	pair<int,int> ps [N];

	for(int n = 0; n<N; n++)
	{
		ps[n].first = A[n];
		ps[n].second = n;
	}

	sort(ps, ps+N);

	vector <bool> visited (N, false);

	int ans = 0;

	for(int n = 0; n<N; n++)
	{
		if(visited[n] == true || ps[n].second == n)
		{
			continue;
		}
		else
		{
			int cycle = 0;
			int j = n;
			while(!visited[j])
			{
				visited[j] = true;
				j = ps[j].second;
				cycle++;
			}
			ans += max(0, cycle-1);
		}
	}

	return ans;
}

int main()
{
    vector<int> A = {3,4,1,5};
   	cout<<min_swaps(A)<<endl;
    return 0;
}
