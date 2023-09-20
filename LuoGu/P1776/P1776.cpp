#include <bits/stdc++.h>

using namespace std;

const int Max = 1e+5+10;

int n,C,dp[Max];

int w[Max],c[Max],m[Max];

int main()
{
    cin>>n>>C;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>c[i]>>m[i];
    }

    for(int i=1;i<=n;i++)
    for(int j=C;j>c[i];j--)
    for(int k=1;k<=m[i]&&k*c[i]<j;k++)
    {
        dp[j] = max(dp[j],dp[j-k*c[i]]+k*w[i]);
    }
    cout<<dp[C]<<endl;
    return 0;
}