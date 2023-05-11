//https://leetcode.cn/problems/multiply-strings/
//43. 字符串相乘
 class Solution {
public:
    string multiply(string num1, string num2) {
   
   string res(num1.size()+num2.size(),'0');
    for(int i =num1.size()-1;i>=0;i--)
    {
        int n1 =num1[i]-'0';
        for(int j=num2.size()-1;j>=0;j--)
        {
            int n2=num2[j]-'0';
            int sum =(res[i+j+1]-'0')+n1*n2;
            res[i+j+1]=sum%10+'0';//当前位置
            res[i+j]+=sum/10;//进位，res[i+j]已被初始化为‘0’
        }
    }
    //当首位是'0'
    for(int r =0;r<num1.size()+num2.size();r++)
    {
       if(res[r]!='0')
          return res.substr(r);//返回r位置及后面的字符
    }
     return "0";//当是“0”字符串的情况
    }
};
