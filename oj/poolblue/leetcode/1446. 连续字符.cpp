//https://leetcode.cn/problems/consecutive-characters/submissions/473962772/ 
class Solution {
public:
    int maxPower(string s) {
        const int len = s.size();
        // 用一个变量maxLen记录最大连续相同字符的长度
        int maxLen = 0;
        for (int i = 0; i < len; i++) // 枚举这个连续相同字符的开始位置的index
        {
            int count = 1; // count: 当前轮循环中连续相同字符的长度, 它的值至少是1, 所以这里初始化为1
            for (int j = i + 1; j < len; j++) // 从开始位置的index的后一个字符继续枚举, 遇到不同的字符就break, 否则遇到相同的计算器就+1
            {
                if (s[j] == s[i])
                    count++;
                else break;
            }
            maxLen = max(maxLen, count);  // 如果当前轮循环中出现更大的连续相同字符长度就更新之
        }
        return maxLen;
    }
};



