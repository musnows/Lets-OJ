//https://leetcode.cn/problems/palindrome-permutation-lcci/
//面试题 01.04. 回文排列
class Solution {
public:
    bool canPermutePalindrome(string s) {
    int len =s.size();
    int count[128]={0};
         for(auto e:s)//遍历字符串进行计数
        {   
            count[e]++;
        }
        int odd=0;
         for(auto i:count)
        {   
            if(i%2==1)//若字符串大小是奇数，只有一个字符为奇数才回文
            odd++;
        }
         return odd<=1;
    }
}; 
