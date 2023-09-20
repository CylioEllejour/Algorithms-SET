#include <bits/stdc++.h>

using namespace std;

const int Max = 10100;

int v[Max];

int dp[Max];

int N, M;

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    dp[0]=1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = M; j >= v[i]; j--)
        {
            dp[j] = dp[j] + dp[j - v[i]];
        }
    }
    cout<<dp[M]<<endl;
    return 0;
}