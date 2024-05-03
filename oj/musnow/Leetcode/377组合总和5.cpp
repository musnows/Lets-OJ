class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 题目说了保证答案符号32位整数范围，所以直接用uint避免中间计算值溢出
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        // 先遍历背包再遍历数字，相当于背包的每一个格子都用过了所有数字
        // 此时就相当于忽略了数字的顺序，求的是组合
        for (int j = 0; j < dp.size(); j++) {
            for (int i = 0; i < nums.size(); i++) {
                // 避免数字越界（当前背包装不下nums[i]）的情况
                if (j - nums[i] >= 0) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};