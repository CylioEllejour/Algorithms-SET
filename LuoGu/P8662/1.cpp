#include <bits/stdc++.h>

using namespace std;

const int Max = 1010;

char mp[Max][Max];

int vist[Max][Max];

int dir[4][2] =
    {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}};

int mark;

void dfs(int x, int y)
{
    vist[x][y] = 1;
    if (mp[x + 1][y] == '#' && mp[x - 1][y] == '#' && mp[x][y - 1] == '#' && mp[x][y + 1] == '#')
    {
        mark = 1;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (vist[nx][ny] == 0 && mp[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    cin>>mp[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] == '#' && vist[i][j] == 0)
            {
                mark = 0;
                dfs(i, j);
                if (mark == 0)
                    ans++;
            }
        }
        cout<<ans<<endl;
    return 0;
}