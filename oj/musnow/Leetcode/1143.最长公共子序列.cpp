class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int result = 0; // 结果集初始化
        // dp[i][j] 代表a中i和b中j下标和下标之前的最长公共子序列的长度
        // i为0和j为0的情况下，长度为0的字符串是不会有公共子序列的，所以可以全部初始化为0
        vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
        // 判断 a[i-1] == b[j-1] 代表公共子序列可以扩展
        // dp[i][j] = dp[i-1][j-1] + 1
        // 其他情况，代表公共子序列不能扩展，那么当前的最长公共子序列和前一位的相同
        // 因为是二维数组，所以“前一位”其实有两种情况，分别是i-1和j-1，用max取最大值
        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] > result) {
                    result = dp[i][j];
                }
            }
        }
        return result;
    }
};
