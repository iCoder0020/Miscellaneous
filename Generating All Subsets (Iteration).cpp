/*
Generating All Subsets (Iteration)
Time Complexity: O(2^N*N) 
*/

#include <bits/stdc++.h>

using namespace std;

int N = 3;

void generate_subsets_iter()
{
	for(int i = 0; i<(1<<N); i++)
	{
		vector <int> V;
		for(int n = 0; n<N; n++)
		{
			if(i&(1<<n))
			{
				V.push_back(n+1);
			}
		}
		for(auto it = V.begin(); it!=V.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	generate_subsets_iter();
	return 0;
}