//https://leetcode.cn/problems/add-strings/
//415. 字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
     int end1= num1.size()-1;
     int end2= num2.size()-1;
     int carry=0;//进位
     string retstr;
     while(end1>=0 ||end2>=0)
     {
         int val1= end1>=0 ?  num1[end1]-'0':0; //对字符进行换算 
         int val2= end2>=0 ?  num2[end2]-'0':0;
         int ret =val1 +val2 +carry;
         if(ret>9)
         {  
             ret-=10;
             carry=1;
         }
         else
         {
             carry=0;
         }
         //进行头插或尾插（效率更高）
         //retstr.insert(retstr.begin(),'0'+ret)//整型换算成字符
         retstr += ('0'+ret);
         --end1;
         --end2;
     }
      if(carry==1)//当出现进位后结束循环时，没有再进位，如‘9’ +‘1’
      {
         //retstr.insert(retstr.begin(),'1')//整型换算成字符
         retstr +='1';
      }
      reverse(retstr.begin(),retstr.end());
      return retstr;
 }
};