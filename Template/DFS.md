```C++
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
```
