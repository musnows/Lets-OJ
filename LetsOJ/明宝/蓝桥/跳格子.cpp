// https://www.lanqiao.cn/problems/553/learning/
#include<iostream>
#define MAX 105
using namespace std;
int n, m, sum = -0x3f3f3f3f;
int map[MAX][MAX];
void dfs(int x, int y, int w)
{
    w += map[x][y];
    if (x == n && y == m)
    {
        if (w > sum)// 动态规划后多种可能相互比较，选出符合题目要求的那个
            sum = w;
        else
            return;
    }

    int next[][2] = { {1,0}, {0,1}, {2,0}, {0,2}, {3,0}, {0,3}, {1, 1}, {1, 2}, {2, 1} };// 下一格共有9种可能

    for (int i = 0; i < 9; i++)
    {
        int wx = x + next[i][0];
        int wy = y + next[i][1];// 找到下一格的位置

        if (wx <= n && wy <= m)
            dfs(wx, wy, w);// 动态规划
    }
}
int main()
{
    cin >> n >> m;//输入n行，m列 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    dfs(1, 1, 0);//1，1当前位置 0是初始权值 
    cout << sum;
    return 0;
}