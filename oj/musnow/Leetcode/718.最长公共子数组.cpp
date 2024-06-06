class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // DP 以i和j结尾的元素最长的子数组的长度
        vector<vector<int>> dp(nums1.size() + 1,
                               vector<int>(nums2.size() + 1, 0));
        // 开始遍历，递推思路：如果i,j前两位相等，那么最长子数组长度就是前一位的子数组长度+1
        // 相当于是以i-1和j-1结尾的最长公共子数组的长度+1
        // dp[i][j] = dp[i-1][j-1]+1
        int result = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result) {
                    result = dp[i][j];
                }
            }
        }
        return result;
    }
};
