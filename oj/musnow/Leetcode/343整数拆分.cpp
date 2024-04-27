class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        // 注意dp0和1都是没有意义的
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            // 每一步都拆分成两种情况
            // j * (i-j)   只是单纯拆成两个数相乘
            // j * dp[i-j] 这种情况相当于沿用之前的结果
            for (int j = 1; j < i - 1; j++) {
                // 因为每一个数都需要计算多次，所以还得判断结果是否比dp[i]自己大
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};