/* 
Permutation Generation
Time Complexity: N^N
*/

#include <bits/stdc++.h>

using namespace std;

void generate_permutations(int N, vector <int> v, int p[])
{
	if(v.size() == N)
	{
		for(auto it = v.begin(); it!=v.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
	{
		for(int i = 1; i<=N; i++)
		{
			if(p[i-1] == 1)
			{
				continue;
			}
			p[i-1] = 1;
			v.push_back(i);
			generate_permutations(N, v, p);
			p[i-1] = 0;
			v.pop_back();
		}
	}
}

int main()
{
	int N;
	cin>>N;
	vector<int> v;
	int p[N] = {0};
	generate_permutations(N, v, p);
	/* 
		
		***or use the in-built function next_permutation***


		vector<int> v;
		for (int i = 1; i <= N; i++) 
		{
			v.push_back(i);
		}
		
		do 
		{
			
			//process permutation

		} while (next_permutation(v.begin(),v.end()));


	*/
	return 0;
}