#include<bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e18

int x,minm,first;

stack<int>S;

void mmin()
{
    cout<<minm<<endl;
}

void mpush(int x)
{
    if(first == INF)
    {
        first = x;
        minm = x;
        S.push(x);
    }
    else
    {
        S.push(x-minm);
        if(x < minm)
            minm = x;
    }
}

void mpop()
{
    if(S.top() < 0)
    {
        if(S.top() < -10000000)
            minm = first;
        else
            minm = minm - S.top();
    }
    S.pop();
}

int32_t main()
{
    int N;
    cin>>N;

    minm = INF;
    first = INF;
    for(int n = 0; n<N; n++)
    {
        cin>>x;
        mpush(x);
    }
    while(!S.empty())
    {
        mmin();
        mpop();
    }
    return 0;
}