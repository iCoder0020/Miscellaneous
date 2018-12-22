/*
nCr%p Calculator
Time Complexity: O(n) 
*/

#include <iostream>

using namespace std;

typedef long long int li;

li modular_exponentiation(li a, li b, li c)
{
	li result = 1;
	a = a%c;
	while(b>0)
	{
		if(b&1)
		{
			result = (result * a)%c;
		}
		b = b>>1;
		a = (a*a)%c;
	}
	return result;
}

li inversemod(li a, li p)
{
	return modular_exponentiation(a, p-2, p);
}

li calculate_nCr_mod_p(li n, li r, li p)
{
	if(r == 0)
	{
		return 1;
	}
	else
	{
		li n_fact, r_fact, n_minus_r_fact;
		li product = 1;
		for(li i = 1; i <= n; i++)
		{
			product = (product%p * i%p)%p;
			if(i == n)
			{
				n_fact = product;
			}
			else if(i == r)
			{
				r_fact = product;
			}
			else if(i == n-r)
			{
				n_minus_r_fact = product;
			}
		}	
		return((((n_fact%p * inversemod(r_fact, p)%p)%p) * inversemod(n_minus_r_fact, p)%p)%p);
	}
}

int main()
{
	li n,r,p;
	cin>>n>>r>>p;
	cout<<"The result is: "<<calculate_nCr_mod_p(n,r,p)<<"\n";
	return 0;
}