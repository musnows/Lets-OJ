// https://leetcode.cn/problems/delete-operation-for-two-strings/
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        // 如果有一个长度为0，那么需要做的操作是另外一个字符串的长度次
        if (word1.size() == 0 || word2.size() == 0)
        {
            return word1.size() == 0 ? word2.size() : word1.size();
        }
        // dp数组，代表a中i-1和b中j-1的字符串相同需要操作的最少次数（i和j可以认为是字符串长度）
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // i和j都为0的时候不需要操作，初始化为0（通过构造函数初始化）
        // 当i=0或者j=0的时候，需要的操作次数是当前的字符串长度，即需要将当前字符串全部删除才能和空字符串相同
        for (int i = 1; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (int j = 1; j <= word2.size(); j++)
        {
            dp[0][j] = j;
        }
        // 开始递推
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                // 情况1，二者相同，不需要删除
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else // 情况2，不同
                {
                    // 把word1中的字符串删除，需要的操作次数是dp[i-1][j]+1
                    // 把word2中的字符串删除，需要的操作次数是dp[i][j-1]+1
                    // 把word1和2中的字符串都删除，需要的操作次数是dp[i-1][j-1]+2
                    // 取三种情况最小值作为最终结果。
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
                }
            }
        }
        // dp数组右下角的值就是最终结果
        return dp[word1.size()][word2.size()];
    }
};