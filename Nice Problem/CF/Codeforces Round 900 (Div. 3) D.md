# D. Reverse Madness

## 题目描述

[Reverse Madness](https://codeforces.com/contest/1878/problem/D)

## 思路

首先通过观察题目可以得到由 $x$ 确定的反转区域 $[a,b]$ 的对称轴同样也是 $[l_i,r_i]$  的对称轴，$x + (r_i+l_i−x) = r_i + l_i$ 且每个更改区间都是不相交或同对称轴包含关系，那么这题就可以使用差分数组来记录更改改逆次数，最后为偶数则区间不变，为奇数则改变一次即可。

## 代码

```C++
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k + 1), r(k + 1), c(n + 1), p(n + 2);
    // c记录x所属区间，p为差分数组
    for (int i = 1; i <= k; i++)
    {
        cin >> l[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> r[i];
        for (int j = l[i]; j <= r[i]; j++)
        {
            c[j] = i;  // 纪录i下的li到ri的范围情况，方便后面x直接访问
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int a = min(x, r[c[x]] + l[c[x]] - x);
        int b = max(x, r[c[x]] + l[c[x]] - x);
        p[a]++, p[b + 1]--;  // 构建差分数组
    }
    for (int i = 1; i <= n; i++)
    { // 对差分数组求前缀和
        p[i] += p[i - 1];
    }
    for (int i = 1; i <= k; i++)  // 枚举每个区间情况
    {
        for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++)
        {
            if (p[j] & 1)
            {
                swap(s[j - 1], s[r[i] + l[i] - j - 1]); // 如果被奇数个区间覆盖，即交换（注意string下标-1）
            }
        }
    }
    cout << s << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
```
