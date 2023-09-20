#include <bits/stdc++.h>

using namespace std;

int t, m;

const int Max = 1e+4;

int me[101][2];

int dp[Max][Max];

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            if (me[i][0] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - me[i][0]] + me[i][1]);
        }
    }
}

int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> me[i][0];
        cin >> me[i][1];
    }
    solve();
    cout<<dp[m][t]<<endl;
    return 0;
}