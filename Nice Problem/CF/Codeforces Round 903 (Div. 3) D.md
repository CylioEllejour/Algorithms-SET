# D. Divide and Equalize

## 题目

[题目描述](https://codeforces.com/contest/1881/problem/D)

## 思路

通过求每个数的因子，及可理解为该数有哪些数乘得。然后纪录存在的因子个数。做完该工作后，最后看每种因子的个数是否与 $n$ 相同，或是 $n$ 的整数倍（这样就说明该因子可以平均分配），当然 $1$ 因子的个数可以任意。

> 该题值得注意的是计数因子的可行性。因为使用该方法得到的是最长因子队，也可以理解为最小分解，存在唯一性，则可行。

## 代码

```C++
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int T;cin>>T;
    while(T--){
        int n;
        cin>>n;
        map<int,int>q;
        for(int i=1;i<=n;i++)  // 统计每个因子的个数
        {
            int t;cin>>t;
            for(int j=2;j<=t/j;j++)
            {
                while(t%j==0){
                    q[j]++;
                    t/=j;
                    // cout<<j<<" ";   // 打印因子便于理解
                }
            }
            // cout<<t<<endl;  // 打印因子便于理解
            q[t]++;
        }
        int f=0;
        for(auto x:q){  // 判断因子是否可均分
            if(x.first<=1) continue;
            if(x.second%n!=0) {f=1;break;}
        }
        if(f==1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
```
