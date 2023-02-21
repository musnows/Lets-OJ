//https://leetcode.cn/problems/valid-anagram/ 
class Solution {
public:
    bool isAnagram(string s, string t) {
     if(s.size()!=t.size())
        return false;

    vector<int> table(26,0);//建立映射表
    for(auto& ch :s )
    {
        table[ch-'a']++;//映射第一个字符串的所有字母，进行计数
    }
    for(auto& ch2 :t)
    {
        table[ch2-'a']--;//遍历第二个字符串，进行计数递减
        if(table[ch2-'a']<0)//若计数小于零，证明字母不匹配
        return false;
    }
    return true;
   
    }
};
