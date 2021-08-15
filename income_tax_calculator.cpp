#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define MAX_INCOME 1e10
#define EPS 0.5

int N;
ld standard_deduction;
ld cess;
ld income_tax;
vector<ld>income_slab;
vector<ld>tax_on_slab;

ld get_income_tax(ld salary) {
    ld sum = 0;
    for(int n = N-1; n>=0; n--) {
        if(salary>=income_slab[n]) {
            sum += (salary-income_slab[n]) * (tax_on_slab[n]/100);
            salary = income_slab[n];
        }
    }
    return sum;
}

bool bs1(ld salary, ld income_tax) {
    if(salary>=standard_deduction)
        salary -= standard_deduction;
    return get_income_tax(salary)>=income_tax;
}

bool bs2(ld salary, ld income_tax) {
    if(salary>=standard_deduction)
        salary -= standard_deduction;
    return get_income_tax(salary)<=income_tax;
}

int32_t main()
{
    cin>>N;
    income_slab.resize(N);
    tax_on_slab.resize(N);
    for(int i = 0; i<N; i++)
        cin>>income_slab[i];
    for(int i = 0; i<N; i++)
        cin>>tax_on_slab[i];
    cin>>standard_deduction;
    cin>>cess;
    cin>>income_tax;
    income_tax = (100/(100+cess))*income_tax;
    ld lo1 = 0, mid1, hi1 = MAX_INCOME;
    while(lo1<hi1) {
        mid1 = lo1 + (hi1-lo1)/2;
        if(bs1(mid1, income_tax))
            hi1 = mid1;
        else
            lo1 = mid1+EPS;
    }
    ld lo2 = 0, mid2, hi2 = MAX_INCOME;
    while(lo2<hi2) {
        mid2 = lo2 + (hi2-lo2+EPS)/2;
        if(bs2(mid2, income_tax))
            lo2 = mid2;
        else
            hi2 = mid2-EPS;
    }
    cout<<setprecision(0)<<fixed<<lo1<<" "<<lo2<<endl;
    return 0;
}