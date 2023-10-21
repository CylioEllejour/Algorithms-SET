# E. Block Sequence

## 题目描述

[题目描述](https://codeforces.com/contest/1881/problem/E)

## 思路

思路转化：本题是求最少的改动次数，前无后效性，因此可以使用DP来解决该问题。

## 代码

```C++
#include <bits/stdc++.h>

using namespace std;

const int Max = 5e+5;

int a[Max];

int dp[Max];

void solve()
{
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=n;i>0;i--)
    {
        dp[i] = dp[i+1]+1;
        if(a[i]+i<=n)
        dp[i] = min(dp[i],dp[i+a[i]+1]);
        // cout<<dp[i]<<' ';
    }
    // cout<<endl;
    cout<<dp[1]<<endl;
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
```
