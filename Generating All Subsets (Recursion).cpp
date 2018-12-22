/*
Generating All Subsets (Recursion)
Time Complexity: O(2^N) 
*/

#include <bits/stdc++.h>

using namespace std;

int N = 3;

vector <int> V;

void generate_subsets_rec(int k)
{
	if(k == N+1)
	{
		for(auto it = V.begin(); it!=V.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
	{
		generate_subsets_rec(k+1);
		V.push_back(k);
		generate_subsets_rec(k+1);
		V.pop_back();
	}
}

int main()
{
	generate_subsets_rec(1);
	return 0;
}