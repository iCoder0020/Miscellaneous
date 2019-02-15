#include <bits/stdc++.h>

using namespace std;

typedef long long int li;

li count(li N)
{
    li cnt = 0;
    li cb = cbrt(N);
    for(li i = 2; i<=cb; i++)
    {
        cnt+=N/(i*i*i);
    }
    return cnt;
}

int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        li M;
        cin>>M;
        li min = 0;
        li max = 5*1e15;
        li N;
        li ans = -1;
        while(1)
        {
            N = (min+max)/2;
            if(max - min <= 1)
            {
                if(count(min) == M)
                {
                    ans = min;
                }
                else if(count(max) == M)
                {
                    ans = max;
                }
                break;
            }
            else if(count(N) == M)
            {
                ans = N;
                max = N;
            }
            else if(count(N) > M)
            {
                max = N-1;
            }
            else
            {
                min = N+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
