class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = 0;
        // 第0天买，第3天卖的利润是prices[3]-prices[0]
        // 也等于 p[3]-p[2] + p[2]-p[1] + p[1]-p[0]
        // 所以最大利润其实就是每天利润之和（前提是利润都是正的）
        for (int i = 1; i < prices.size(); i++) {
            // 计算昨天买今天卖能获得多少利润
            // 如果大于0就加入进去
            count += max(prices[i] - prices[i - 1], 0);
        }
        return count;
    }
};