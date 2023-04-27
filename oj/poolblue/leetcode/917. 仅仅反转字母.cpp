//https://leetcode.cn/problems/reverse-only-letters/
//917. 仅仅反转字母
class Solution {
public:
 bool isLetter(char ch)
{   //判断是不是英文字母
   if(ch >= 'a' && ch <= 'z')
     return true;
    else if(ch >= 'A' && ch <= 'Z')
    return true;
     else
   return false;
}
    string reverseOnlyLetters(string s) {
        //迭代器
        string ::iterator left=s.begin();
        string ::iterator right=s.end()-1;
        while(left<right)//利用迭代器从左右同时遍历，进行交换
        {
        while(left < right && !isLetter(*left))
        ++left;

       while(left < right && !isLetter(*right))
       --right;

      swap(*left, *right);
       ++left;
      --right;
     
     }
      return s;
    }
};