/* 
Square Root of a Number 
Time Complexity: O(logN)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define eps 0.0000000001

int main()
{
	ld N;
	while(cin>>N)
	{
		ld min, max, mid;
		ld ans;
		min = 0;
		max = N;
		while(1)
		{
			mid = (min + max)/2;
			if(abs(mid*mid - N) < eps)
			{
				ans = mid;
				break;
			}
			else if(mid*mid - N >= eps)
			{
				max = mid - 1;
			}
			else
			{
				min = mid + 1;
			}
		}
		cout<<setprecision(10)<<fixed<<ans<<endl;
	}
	return 0;
}