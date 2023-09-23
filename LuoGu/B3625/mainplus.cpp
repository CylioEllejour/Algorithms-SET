#include <bits/stdc++.h>

using namespace std;

const int Max = 110;

char graph[Max][Max];

int used[Max][Max];  //标记已经走过的路

int n, m, goal_x, goal_y;

int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};

vector<string> ans_dir;

void DFS(int x, int y, vector<string> dir)
{
    if (x == goal_x && y == goal_y) // 到达终点的条件
    {
        ans_dir = dir;
        return;
    }
    // 遍历四个方向
    for (int i = 0; i < 4; i++)
    {
        // 如果没有走过这个格子
        int new_x = x + px[i], new_y = y + py[i];

        vector<string> new_dir;

        new_dir = dir;

        if (i == 0) // 将路径载入容器
            new_dir.push_back("↓");
        if (i == 1)
            new_dir.push_back("→");
        if (i == 2)
            new_dir.push_back("↑");
        if (i == 3)
            new_dir.push_back("←");

        if (new_x > 0 && new_x <= m && new_y > 0 && new_y <= n && used[new_x][new_y] == 0 && graph[new_x][new_y] != '#')
        {
            used[new_x][new_y] = 1;     // 将该格子设为走过
            DFS(new_x, new_y, new_dir); // 递归下去
        }
    }
}

int main()
{
    cin >> n >> m;
    cin>>goal_x;
    cin>>goal_y;

    // 构造地图，注意哪个下表代表是x，哪个下表代表的是y
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> graph[j][i];
    }

    vector<string> dir; // 使用vector容器来存储答案路径

    DFS(1, 1, dir);

    for (int i = 0; i < ans_dir.size(); i++) // 输出结果
    {
        cout << ans_dir[i] << " ";
    }
    cout << endl;

    return 0;
}