//459. 重复的子字符串（s+s,或KMP算法） 
//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
//输入: s = "abab"
//输出: true
//解释: 可由子串 "ab" 重复两次构成。

class Solution {
public:
	// 方法一：拼接s+s，在其中找s（记得把s+s的第一位和最后一位删掉，不然一定能找到s+s中的s呀）
//    bool repeatedSubstringPattern(string s) {
//        string newS = s+s;
//        newS.erase(newS.begin());
//        newS.erase(newS.end()-1);
//        if(newS.find(s)!=std::string::npos)
//            return true;
//
//        return false;
//    }

// 方法二：KMP数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，如果这个周期可以被整除，就说明整个数组就是这个周期的循环。
    void getNext(int* next, const string &s)
    {
        int j = 0; 
        next[0] = 0;
        for(int i = 1; i<s.size(); i++)
        {
            while(j>0 && s[i]!=s[j])
            {
                j = next[j-1];
            }
            if(s[i]==s[j])
                j++;
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0)
            return 0;
        
        int next[s.size()];
        getNext(next, s);

        int len = s.size();
        if(next[len-1]!=0 && len%(len-next[len-1]) == 0)// 能被整除 
            return true;
        return false;
    }
};
