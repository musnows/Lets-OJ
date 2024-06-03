class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 1;// 结果长度
        // 最开始的时候，每一位的最长子序列认为是它自己
        vector<int> dp(nums.size(),1);
        // 从1开始遍历，因为0只有一个元素，没有意义
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    // 大于，沿用之前的结果
                    dp[i] = max(dp[i], dp[j] + 1);
                } 
            }
            // 更新结果最大值
            if(dp[i] > ret){
                ret = dp[i];
            }
        }
        return ret;
    }
};