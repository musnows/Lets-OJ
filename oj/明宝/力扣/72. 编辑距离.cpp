// https://leetcode.cn/problems/edit-distance/description/ 
//72. 编辑距离
//https://www.programmercarl.com/0072.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.html#%E6%80%9D%E8%B7%AF
//和这道题一念之差：https://leetcode.cn/problems/delete-operation-for-two-strings/description/
class Solution {
public:
// dp[i][j]:让word1[0,i-1]和word2[0,j-1]相等的最小步数
// if(word1[i-1]==word2[j-1])dp[i][j] = dp[i-1][j-1];// 不用操作
// else dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1);// 删word1的[删/增效果相同]（操作+1）删word2的（操作+1）两个都删[相当于改]（操作+1）
    int minDistance(string word1, string word2) {
         vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(int i = 0; i<=word1.size(); i++) dp[i][0] = i;
        for(int j = 0; j<=word2.size(); j++) dp[0][j] = j;
        for(int i = 1; i<=word1.size(); i++) 
        {
            for(int j = 1; j<=word2.size(); j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1, dp[i-1][j-1]+1));
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
