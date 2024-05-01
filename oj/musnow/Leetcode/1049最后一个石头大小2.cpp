class Solution {
public:
    // 首先需要学会转换问题，题目给出的就是每次选两个石头相撞，减去小的石头值留下的碎片
    // 要求最终剩下的碎片大小，本质上是将数组分割成两个子集，且需要获取这两个子集的最小差值
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto& i : stones) {
            sum += i;
        }
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        // 简化为01背包问题，我们需要知道只背一半(sum/2)的石头最多可以背到多少
        // 每个石头的重量是stones[i]，价值也是stones[i]
        // 通过01背包的递推公式，可以得到容量为sum/2的背包最多可以背到多少石头
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // 既然我们获得了这个最大值，且每个石头顶多装入一次
        // 那么sum减去得到的这个值，就是石堆另外一半的石头重量
        // 两个重量相减，即可以得到相撞的最小结果
        return sum - dp[target] - dp[target];
    }
};