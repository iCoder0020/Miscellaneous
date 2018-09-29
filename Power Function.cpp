/*
Power Function
Time Complexity: O(logx) 
*/

#include <iostream>

using namespace std;

typedef long long int li;

li power(li a, li x)
{
	if(x < 0)
	{
		cout<<"No negative exponents allowed.\n";
		return 0;
	}
	if(a == 1 || x == 0)
	{
		return 1;
	}
	li result = a;
	if(x == 1)
	{
		return result;
	}	
	else if(x&1)
	{
		x--;
		return result*power(result,x);
	}
	else
	{
		x = x>>1;
		result = result*result;
		return power(result,x);
	}
}

int main()
{
	li a,x;
	cin>>a>>x;
	cout<<"The result is: "<<power(a,x)<<"\n";
	return 0;
}