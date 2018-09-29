/* 
Euclidean GCD
Time Complexity: O(log(a+b))
*/

#include <iostream>

using namespace std;

typedef long long int li;

li GCD(li a, li b)
{
	if(b>a)
	{
		return GCD(b, a);
	}
	if(b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a%b);
	}
}

int main()
{
	li a,b;
	cin>>a>>b;
	cout<<GCD(a,b)<<"\n";
	return 0;
}