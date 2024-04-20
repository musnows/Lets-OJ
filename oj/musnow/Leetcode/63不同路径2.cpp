class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // m 是行，n是列
        // dp方程是 dp[i][j] = dp[i-1][j] + dp[i][j-1]
        vector<vector<int>> v(m, vector<int>(n));
        // 因为只能向右和向下走，从0,0开始
        // 所以能直接推出来一部分结果，将第一行和第一列都初始化为1
        bool isBlock = false; // 是否有阻碍？
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1 || isBlock) {
                v[i][0] = -1; // 不能走的初始化为负一
                isBlock = true; // 注意，只要有一个阻碍，就不能往下走了
            } else {
                v[i][0] = 1;
            }
        }
        isBlock = false;
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1 || isBlock) {
                v[0][j] = -1; // 不能走的初始化为负一
                isBlock = true; // 注意，只要有一个阻碍，就不能往下走了
            } else {
                v[0][j] = 1;
            }
        }
        // 其他部分是用dp计算
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 当前的路径数量是上一位往右（v[i][j-1]）和上一位往下（v[i-1][j]）的和
                // 但是需要判断能不能走到这里，如果两个路径都不能走，则跳过这个位置
                int left = v[i][j - 1];
                int up = v[i - 1][j];
                // 两个都不能走，或者当前位置有障碍，说明当前位置到不了
                if (obstacleGrid[i][j] == 1 || (left < 0 && up < 0)) {
                    v[i][j] = -1;
                    continue;
                }
                // 到的了，修正值
                if (left < 0) {
                    left = 0; // 不能走的初始化为0
                }
                if (up < 0) {
                    up = 0;
                }
                v[i][j] = up + left;
            }
        }
        // 因为我是用-1来设置到不了的，最终就需要修正为0
        return v[m - 1][n - 1] == -1 ? 0 : v[m - 1][n - 1];
    }
};