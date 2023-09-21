#include <bits/stdc++.h>

using namespace std;

const int Max = 110;

char graph[Max][Max];

int used[Max][Max];

int n, m, goal_x, goal_y;

int flag = 0;

int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};

void DFS(int x, int y)
{
    if(x==goal_x&&y==goal_y)
    {
        flag = 1;
        return;
    }
    // 遍历四个方向
    for (int i = 0; i != 4; ++i)
    {
        // 如果没有走过这个格子
        int new_x = x + px[i], new_y = y + py[i];

        if(new_x > 0 && new_x <= n && new_y > 0 && new_y <= m && used[new_x][new_y] == 0 && !flag&&graph[new_x][new_y]!='#')
        {
            used[new_x][new_y] = 1; // 将该格子设为走过
            DFS(new_x, new_y); // 递归下去
        }
    }
}

int main()
{
    cin >> n >> m;
    goal_x = n;
    goal_y = m;
    for (int i = 1; i <= n; i++)
    {
        for(int j= 1;j<=m;j++)
        cin >> graph[i][j];
    }
    DFS(1,1);
    if (flag == 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}