class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t sz1 = word1.size(), sz2 = word2.size();
        if (sz1 == 0 || sz2 == 0) {
            return sz1 == 0 ? sz2 : sz1;
        }
        // 1中i之前和2中j之前的字符串的最小编辑距离
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));
        // 初始化情况，dp[0][0]是两个空字符串，不需要编辑，初始化为0
        // i=0的情况和j=0的情况都是初始化为另外一个字符串的长度
        for (int i = 1; i <= sz1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= sz2; j++) {
            dp[0][j] = j;
        }
        // 开始遍历
        for (int i = 1; i <= sz1; i++) {
            for (int j = 1; j <= sz2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // 二者相等，不需要做额外操作，沿用前一位的结果
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 二者不相等，分为三种操作情况，其中插入一个字符和删除一个字符等价
                    // 1.在word1中删除一个字符
                    int action1 = dp[i - 1][j] + 1;
                    // 2.在word2中删除一个字符
                    int action2 = dp[i][j - 1] + 1;
                    // 3.二者都删除一个字符，但这会比第四点耗费多一次操作，没意义
                    // int action3 = dp[i - 1][j - 1] + 2;
                    // 4.在word1或者word2中替换一个字符，那就是使用一次操作让二者相等
                    int action4 = dp[i - 1][j - 1] + 1;
                    // 得到最小值
                    dp[i][j] = min(min(action1, action2), action4);
                    // cout << i << " " << j << ":" << dp[i][j] << endl;
                }
            }
        }
        return dp[sz1][sz2];
    }
};
