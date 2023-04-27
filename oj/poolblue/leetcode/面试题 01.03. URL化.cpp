//https://leetcode.cn/problems/string-to-url-lcci/
// 面试题 01.03. URL化
class Solution {
public:
    string replaceSpaces(string S, int length) {
    //利用倒序遍历，
     int fillidx=S.size()-1;//标记真实字符串的最后位置
     for(int i =length-1;i>=0;--i)//从最后一个字符开始遍历
     {
         if(S[i]==' ')//遇到空格，就插入字符
         {
              S[fillidx]='0';
              S[fillidx-1]='2';
              S[fillidx-2]='%';
               fillidx -=3;//把标记真实字符串的位置往前移动三个位置
         }
         else
         {
             S[fillidx]=S[i];//遇到字符，就普通拷贝到真实字符串位置
             --fillidx;//往前移动一个位置
         }
     }
     S = S.substr(fillidx+1);
    return S;
    }
};

