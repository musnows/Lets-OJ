//https://leetcode.cn/problems/word-break/description/
//139. 单词拆分

//https://www.programmercarl.com/0139.%E5%8D%95%E8%AF%8D%E6%8B%86%E5%88%86.html#%E6%80%9D%E8%B7%AF 

class Solution {
public:
// 本题是求排列数，因为aba和aab是两种结果，单词拼接的顺序是有讲究的.所以先遍历背包再遍历物品
// dp[i]意味着长度为i的字符串s是否可以用字典中出现的单词拼出
// 如果确定dp[j]是true，且 [j, i] 这个区间的子串出现在字典里，那么dp[i]一定是true。（j < i 
// 所以递推公式是if([j, i] 这个区间的子串出现在字典里 && dp[j]是true) 那么 dp[i] = true。
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());// set方便查找
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i<=s.size(); i++)// 遍历背包
        {
            for(int j = 0; j<i; j++)// 遍历物品
            {
                string word = s.substr(j, i-j);//substr(起始位置，截取的个数)
                if(wordSet.find(word)!=wordSet.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};
