/* 
Next Greater Element
Time Complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int A[N];
		for(int n = 0; n<N; n++)
		{
			cin>>A[n];
		}
		stack <int> stk;
		int nge[N];
		nge[N-1] = -1;
		stk.push(A[N-1]);
		for(int n = N-2; n>=0; n--)
		{
			if(stk.empty())
			{
				nge[n] = -1;
			}
			else
			{
				if(A[n] < stk.top())
				{
					nge[n] = stk.top();
				}
				else
				{
					while(!stk.empty() && A[n] >= stk.top())
					{
						stk.pop();
					}
					if(stk.empty())
					{
						nge[n] = -1;
					}
					else
					{
						nge[n] = stk.top();
					}
				}
			}
			stk.push(A[n]);
		}
		for(int n = 0; n<N; n++)
		{
			cout<<nge[n]<<" ";
		}
		cout<<endl;
	}
	return 0;
}