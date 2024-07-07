class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) {
            return 0;
        }
        // dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。
        vector<vector<uint64_t>> dp(s.size() + 1,
                                     vector<uint64_t>(t.size() + 1, 0));
        // 初始化，分为j=0还有i=0的情况，我们只需要手动处理j=0的情况；
        // 此时s不管多长都可以删除所有元素构成一个空字符串，所以结果应该是1
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = 1;
        }
        // 开始遍历
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        // 最终dp数组右下角的就是结果，完整的t和完整的s
        return dp[s.size()][t.size()] % 1000000007;
    }
};
