class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 数组长度最小为2
        if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }
        // 这道题是在普通爬楼梯的基础上加了一个花费计算
        // dp[i] 是爬到i楼的最小花费，那么递推公式如下
        // dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2])
        // 因为只和两个数有关，所以可以初始化定长数组
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = 0;
        // 本题说的爬到顶部是数组越界，所以i等于cost.size()
        for (int i = 2; i <= cost.size(); i++) {
            int tmp = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = tmp;
        }
        return dp[1];
    }
};
// https://leetcode.cn/problems/min-cost-climbing-stairs/description/