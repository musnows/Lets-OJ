//28. 找出字符串中第一个匹配项的下标（KMP算法） 
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
class Solution {
public:
    // 获取next数组
    void getNext(int* next, const string &s)
    {
        // init
        int j = 0;// j是前缀末尾，也是最长相等前后缀的长度
        next[0] = 0;// next数组用来存最长相等前后缀
        for(int i = 1; i<s.size(); i++)// i是后缀末尾，从1开始
        {
            // no equal
            while(j>0 && s[i] != s[j])
            {
                j = next[j-1];
            }
            // equal
            if(s[i] == s[j])
            {
                j++;
            }
            // next
            next[i] = j;
        }
        
    }
    int strStr(string haystack, string needle) {
        // KMP算法
        if(needle.size() == 0)
            return 0;

        int next[needle.size()];
        getNext(next, needle);

        // 找最长相等前缀后缀的长度，前面的部分已经相等了，就从那开始继续往后比较。例子：aabaabaaf和aabaaf
        int j = 0; 
        for(int i = 0; i<haystack.size(); i++)
        {
            while(j>0 && haystack[i]!=needle[j])
                j = next[j-1];

            if(haystack[i] == needle[j])
                j++;

            if(j == needle.size())
                return i-needle.size()+1;
        }
        return -1;
    }
};
