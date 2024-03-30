class Solution {
public:
    int uniquePaths(int m, int n) {
        // m 是行，n是列
        // dp方程是 dp[i][j] = dp[i-1][j] + dp[i][j-1]
        vector<vector<int>> v(m, vector<int>(n));
        // 因为只能向右和向下走，从0,0开始
        // 所以能直接推出来一部分结果，将第一行和第一列都初始化为1
        for (int i = 0; i < m; i++) {
            v[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            v[0][j] = 1;
        }
        // 其他部分是用dp计算
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                v[i][j] = v[i - 1][j] + v[i][j - 1];
            }
        }
        return v[m - 1][n - 1];
    }
};

// https://leetcode.cn/problems/unique-paths/