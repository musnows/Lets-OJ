class Solution {
public:
    // 本质上也是一个01背包的问题，只不过这一次重量有两个维度来考虑
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 创建二维数组，dp[i][j]代表i个0和j个1的子集有几个
        // 初始值都是0，因为dp[0][0]是0
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 遍历字符串，先计算每个字符串的0和1的数量
        for (auto& s : strs) {
            // 遍历计算这个字符串里面有几个0和几个1
            int zero = 0, one = 0;
            for (auto& c : s) {
                c == '0' ? zero++ : one++;
            }
            // 遍历动归数组，两种情况
            // 1.不把当前数组纳入子集，则dp[i][j]保持不变
            // 2.将当前数组纳入，dp[i-zero][j-one]+1
            //      含义是减去当前字符串的0和1的个数后，子集中的最大元素数量加一(加一是加上当前字符串)
            // 求这两个情况的最大值
            for(int i = m;i>=zero;i--){
                for(int j = n;j>=one;j--){
                    dp[i][j] = max(dp[i][j],dp[i-zero][j-one]+1);
                }
            }
        }
        return dp[m][n];
    }
};