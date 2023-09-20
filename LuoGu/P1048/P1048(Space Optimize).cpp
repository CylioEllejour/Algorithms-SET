#include <bits/stdc++.h>

using namespace std;

int t, m;

const int Max = 1e+4;

int me[101][2];

int dp[Max][Max];

int solve()
{
    int now = 0;
    int old = 1;
    for (int i = 1; i <= m; i++)
    {
        swap(now,old);
        for (int j = 0; j <= t; j++)
        {
            if (me[i][0] > j)
                dp[now][j] = dp[old][j];
            else
                dp[now][j] = max(dp[old][j], dp[old][j - me[i][0]] + me[i][1]);
        }
    }
    return dp[now][t];
}

int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> me[i][0];
        cin >> me[i][1];
    }
    cout<<solve()<<endl;;
    return 0;
}