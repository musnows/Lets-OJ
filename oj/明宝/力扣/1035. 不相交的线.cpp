//1035. 不相交的线
//https://www.programmercarl.com/1035.%E4%B8%8D%E7%9B%B8%E4%BA%A4%E7%9A%84%E7%BA%BF.html
//https://leetcode.cn/problems/uncrossed-lines/description/
class Solution {
public:
// 和1143. 最长公共子序列的代码一样https://leetcode.cn/problems/longest-common-subsequence/

    int maxUncrossedLines(vector<int>& text1, vector<int>& text2) {
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
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
