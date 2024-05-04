class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 用sets来提高查询速度
        unordered_set<string> sets(wordDict.begin(), wordDict.end());
        // 字符串就是背包，wordDict是物品
        vector<bool> dp(s.size() + 1, false);
        // dp[i] 定义为 s[0,i-1] 是否可以被拆分成字典中的单词
        // dp[0]是递推的开始，必须设置为true，本身没有意义
        dp[0] = true;
        // 本题目中，物品必须按一定顺序才有可能装满背包，所以顺序是有关系的
        // 也就是求的是排列，必须外层遍历背包
        for (int i = 1; i <= dp.size(); i++) {
            // 枚举[j,i-1]区间内的所有字符串，判断是否存在于字典中
            for (int j = 0; j < i; j++) {
                string str = s.substr(j, i - j);
                // dp[j] 为 true 代表j之前的字符串可以被正常拆分
                // 只有j之前的可以被拆分，且[j,i-1]的存在于字典中，才代表当前位置可以设置为true
                if (dp[j] && sets.count(str) != 0) {
                    dp[i] = true;
                    break; // 跳出内层循环
                }
            }
        }
        return dp[s.size()];
    }
};
// https://leetcode.cn/problems/word-break/description/