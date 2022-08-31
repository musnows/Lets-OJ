//https://leetcode.cn/problems/reverse-words-in-a-string-iii/
//557. 反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s) {
    int len=s.size();//记录长度
    int i=0;//计数
    while(i<len)//遍历字符串
   {  int start=i;
      while(i<len && s[i]!=' ')//如果不是空格，则继续遍历,要控制不要超出字符串长度
      {
          i++;
      }
      int left=start;
      int right=i-1;
      while(left<right)//原地进行交换翻转单词
      {
          swap(s[left],s[right]);
          ++left;
          --right;
      }
      while(i<len && s[i]==' ')//继续遍历，控制不要超出字符串长度
      {
          i++;
      }
       
   }
   return s;
    }
};
