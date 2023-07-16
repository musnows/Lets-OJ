//1143. 最长公共子序列
//
//https://leetcode.cn/problems/longest-common-subsequence/description/
//https://www.programmercarl.com/1143.%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
class Solution {
public:
// dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp (text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = 1; i<=text1.size(); i++)
        {
            for(int j = 1; j<=text2.size(); j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);// 这里要小心！可以举例推出
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
