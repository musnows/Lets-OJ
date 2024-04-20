class Solution {
public:
    int fib(int n) {
        if (n <= 1) {
            return n;
        }
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            // 当前的值是前两个的值相加
            int tmp = dp[0] + dp[1];
            dp[0] = dp[1]; // 移动前两位
            dp[1] = tmp;
        }
        return dp[1];
    }
};

// 简单题，dp推导是dp[i] = dp[i-1] + dp[i-2]
// 可见当前值只和前两位的值有关。所以我们只需要保存前两位的值就可以了，遍历从2开始
// dp[0] 和 dp[1] 的初始化值都已给出，是0和1
