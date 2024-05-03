class Solution {
public:
    int numSquares(int n) {
        // 完全平方数就可以当作背包中的物品,n是背包容量
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // 这个只是为了递推初始化的
        for (int i = 1; i < dp.size(); i++) {
            // 每一次操作的都是j的平方，就相当于遍历小于n的完全平方数数组
            // dp[i]的含义是容量为i的背包最少可以用几个完全平方数装满
            // 每一次遍历的时候都是找小于当前背包容量i的完全平方数
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// https://leetcode.cn/problems/perfect-squares/