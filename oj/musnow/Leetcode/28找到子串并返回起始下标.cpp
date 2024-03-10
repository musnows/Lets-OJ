class Solution {
    public:
    void getNext(int* next,const std::string& s)
    {
        int j = 0;
        next[0] = 0; // 初始化next数组第一位（第一位是不存在前缀和后缀，肯定为0）
        for(int i=1;i<s.size();i++) //遍历要从字符串第二位开始
        {
            // 后续需要取j-1作为下标的操作，所以j必须大于0
            // 当j和i的字符二者不匹配的时候，就需要往前回溯
            while(j>0 && s[i] != s[j])
            {
                j = next[j-1]; // 回溯到前一位下标在next数组中的元素
            }
            // 二者匹配，j+1
            if(s[i] == s[j])
            {
                j++;
            }
            // 赋值next数组
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        // 子串为空肯定找不到
        if(needle.size() == 0){
            return -1;
        }

        int next[needle.size()];
        getNext(next,needle);
        int j=0;
        for(int i=0;i<haystack.size();i++)
        {
            while(j>0 && haystack[i] != needle[j])
            {
                j = next[j-1]; // 往前回溯一位
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            // j已经超出大小，说明子串完全匹配，成功。
            if(j>=needle.size())
            {
                return (i - needle.size() + 1); // 返回子串的起始下标
            }
        }
        return -1;//没找到
    }
};

// 这是一道kmp算法的题目，主要是记住next数组的构建
// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/