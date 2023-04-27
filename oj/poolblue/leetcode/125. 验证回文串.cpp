//https://leetcode.cn/problems/valid-palindrome/
//125. 验证回文串 
class Solution {
public:
    bool isPalindrome(string s) {
    string pd;
    for(auto ch : s)//遍历字符串
    {
       if(isalnum(ch))//辨别是否0-9，a-z，A-Z数字或字母
       {
           pd+=tolower(ch);//如果是大写转换为小写，
       }
    }
    int len=pd.size();
    //双指针
    int left=0;
    int right=len-1;
    while(left<right)
    {
        if(pd[left]!=pd[right])//如果不相等，返回false
        {
        return false;
        }
        ++left;
        --right;
     }
     return true;//遍历结束，返回true
    }
};
