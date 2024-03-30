// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
// 这道题很简单，只要在最低点买入，就能算出收益最大值。
// 注意当前选择的最低点必须在计算节点的左侧（不然就不符合现实情况了）


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = -1; // 最大收益
        int minPrice = prices[0]; // 当前的最小价格
        for(auto& i:prices)
        {
            // 当前值减去最小价格得到最大收益
            // 这里第一次遍历的时候会算出来prices[0]-prices[0]，这是合理的
            // 因为第一天是没有办法卖出股票的，不存在最大获利
            maxProfit = max(maxProfit,i-minPrice);
            // 需要更新最小价格，保证最小价格是在当前值之前的
            minPrice = min(minPrice,i);
        }

        return maxProfit;
    }
};