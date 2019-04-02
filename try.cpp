#include <bits/stdc++.h>

#define int long long
#define max_ans 10000

using namespace std;

int32_t main()
{
    int TE;
    cin>>TE;
    for(int t = 0; t<TE; t++)
    {
        int R,C;
        cin>>R>>C;
        char grid[R][C];
        int dp[R][C];

        for(int i = 0; i<R; i++)
            for(int j = 0; j<C; j++)
            {
                dp[i][j] = max_ans;
            }

        for(int i = 0; i<R; i++)
            for(int j = 0; j<C; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j] == '1')
                    dp[i][j] = 0;
            }

        for(int m = 0; m<max(R,C); m++)
            for(int i = 0; i<R; i++)
                for(int j = 0; j<C; j++)
                {
                    if(i>0)
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    if(i<R-1)
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                    if(j>0)
                        dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                    if(j<C-1)
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                }

        int max_dist;
        int ans = max_ans;

        for(int x = 0; x<R; x++)
            for(int y = 0; y<C; y++)
            {
                max_dist = 0;
                int dp_copy[R][C];
                for(int i = 0; i<R; i++)
                    for(int j = 0; j<C; j++)
                        dp_copy[i][j] = dp[i][j];
                dp_copy[x][y] = 0;
                for(int m = 0; m<max(R,C); m++)
                    for(int i = 0; i<R; i++)
                        for(int j = 0; j<C; j++)
                        {
                            if(i>0)
                                dp_copy[i][j] = min(dp_copy[i][j], dp_copy[i-1][j] + 1);
                            if(i<R-1)
                                dp_copy[i][j] = min(dp_copy[i][j], dp_copy[i+1][j] + 1);
                            if(j>0)
                                dp_copy[i][j] = min(dp_copy[i][j], dp_copy[i][j-1] + 1);
                            if(j<C-1)
                                dp_copy[i][j] = min(dp_copy[i][j], dp_copy[i][j+1] + 1);
                        }
                for(int i = 0; i<R; i++)
                    for(int j = 0; j<C; j++)
                        if(dp_copy[i][j] >= max_dist)
                            max_dist = dp_copy[i][j];
                if(max_dist < ans)
                    ans = max_dist;
            }
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
    return 0;
}