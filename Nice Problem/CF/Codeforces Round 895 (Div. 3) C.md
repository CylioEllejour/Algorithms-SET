# Non-coprime Split

## 题目

[题目描述](https://codeforces.com/problemset/problem/1872/C)

## 思路

假设分出来的 $a$ 和 $b$ 都有因子 $k$，那么 $a+b$ 也一定有因子 $k$，并且至少还存在另一个最小为 $2$ 的因子，才能分出 $a$ 和 $b$。

所以可以发现，质数是不满足要求的，考虑一个合数，一定可以拆成 $k×a$ 的形式，那么就直接构造成 $k$ 和 $k×(a−1)$ 就满足条件了。

所以我们可以提前线性筛预处理出每个数的最小质因子，然后遍历 $n$ 到 $m$，找到第一个合数，然后直接拆开就好了。

## 代码

```C++
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l,r;
        cin>>l>>r;
        for(int i=max(4,l);i<=r;i++)  //遍历和数
        for(int j=2;j*j<=i;j++){  //找因子
            if(i%j==0){
                cout<<j<<" "<<i-j<<endl; 
                return;
            }
        }
        cout<<-1<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```
