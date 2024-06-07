class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        // 初始化，第一行和第一列
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                result = 1;
            } else if (i > 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int j = 0; j < nums2.size(); j++) {
            if (nums2[j] == nums1[0]) {
                dp[0][j] = 1;
                result = 1;
            } else if (j > 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        // 开始遍历
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] > result) {
                    result = dp[i][j];
                }
            }
        }

        return result;
    }
};
