//300. 最长递增子序列

//https://leetcode.cn/problems/longest-increasing-subsequence/
//https://www.programmercarl.com/0300.%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

class Solution {
public:
// dp[i]表示以i结尾的递增数组长度
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        vector<int>dp (nums.size(), 1);// 初始化部分要注意！至少包含自己所以初始化成1
        int res = 0;
        // j<i && nums[j]<nums[i]才符合条件
        for(int i = 1; i<nums.size(); i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            // cout<<dp[i]<<" ";
            res = max(res, dp[i]);// 取长的子序列
        }
        return res;

    }
};
