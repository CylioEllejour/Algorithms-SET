#include <bits/stdc++.h>

using namespace std;

const int Max = 1e+5+10;

int dp[Max];

int n,k;

int main()
{
    dp[0]=1;
        cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(i,k);j++)
        {
            dp[i] = (dp[i-j]+dp[i])%100003;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}