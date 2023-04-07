//https://leetcode.cn/problems/longest-palindromic-substring/description/
//给你一个字符串 s，找到 s 中最长的回文子串。
//如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

class Solution {
public:
    bool isReverse(const string& s,int begin,int end)
    {
        while(begin<end)
        {
            if(s[begin]!=s[end])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        if(s.size()<2)
        {
            char a = s[0];
            string tmp="";
            tmp+=a;
            return tmp;
        }
        int i=0,j=0;
        int max = 0;
        int index[2];
        for(i=0;i<s.size()-1;i++)
        {
            for(j=i+1;j<s.size();j++)
            {
                bool ret = isReverse(s,i,j);
                if(ret && (j-i)>max)
                {
                    max = j-i;
                    index[0]=i;
                    index[1]=j;
                    cout<< "i " << i << " j " << j << endl;
                }
            }
        }
        cout<< "index " <<  index[0] << " - " <<  index[1] << endl;
        string tmp(s,index[0],max+1);
        return tmp;
    }
};