class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp[i][j]代表s中[i,j]范围内最长公共子序列的长度
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // i和j相等的情况初始化为1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        // 开始递推
        for (int i = n - 1; i >= 0; i--) {
            // j 必须大于i
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
