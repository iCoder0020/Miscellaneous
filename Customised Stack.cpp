/*
Customised Stack
Time Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int temp;
	stack<int>stk;
	int min;
	for(int n = 0; n<N; n++)
	{
		cin>>temp;
		if(stk.empty())
		{
			min = temp;
			stk.push(temp);
		}
		else
		{
			if(temp < min)
			{
				stk.push(2*temp - min);
				min = temp;
			}
			else
			{
				stk.push(temp);
			}
		}
	}
	for(int n = 0; n<N; n++)
	{
		temp = stk.top();
		if(temp < min)
		{
			int minm = min;
			min = 2*min - temp;
			temp = (temp + min)/2;
			cout<<temp<<" "<<minm<<endl;
		}
		else
		{
			cout<<temp<<" "<<min<<endl;
		}
		stk.pop();
	}
	return 0;
}