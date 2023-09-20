#include <bits/stdc++.h>

using namespace std;

const int Max = 105;

int w[Max][Max], c[Max][Max];

int dp[Max];

int n, m;

int main()
{
    // cin >> n >> m;
    while (scanf("%d %d", &n,& m) && n && m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> w[i][j];
                c[i][j] = j;
            }
        }
        memset(dp,0,sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 0; j--)
            {
                for (int k = 1; k <= m; k++)
                {
                    if (j >= c[i][k])
                        dp[j] = max(dp[j], dp[j - c[i][k]] + w[i][k]);
                }
            }
        }
        cout << dp[m] << endl;
    }
    return 0;
}