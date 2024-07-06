class Solution {
public:
    bool isSubsequence(string s, string t) {
        // s更长肯定不会是t的子序列
        if (s.size() > t.size()) {
            return false;
        }
        // dp[i][j]表示以下标i-1为结尾的字符串s，和以下标j-1为结尾的字符串t，相同子序列的长度为dp[i][j]
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        // 两种递推的情况
        //  1.当前s和t相等，代表相同子序列长度可以扩张 dp[i][j] = dp[i-1][j-1]+1;
        //  2.当前s和t不相等，相同子序列长度不可扩张，过渡于上一个
        //          如果是普通题目，“上一个”分为两种情况 dp[i-1][j] 和
        //          dp[i][j-1]
        //          但是本题判断s是否为t的子序列，所以我们不能从s中删除元素，只能从t中删除元素
        //          所以只能使用 dp[i][j-1]
        //          代表从t中删除一个元素（删除的其实就是当前元素j-1）
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        // 如果t中包含s，那么最终得到的相同子序列长度应该是s.size()
        return dp[s.size()][t.size()] == s.size();
    }
};
