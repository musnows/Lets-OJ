//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
//把字符串转换成整数 
class Solution {
public:
    int StrToInt(string str) {
        int flag=0;//标记数字正负
        long long sum=0;
        for(auto s:str)
        {
            if(s=='-'||s=='+')//判断第一个
            {  
            if(!(str.find('+',0)||str.find('-',0)))//如果‘+’‘-’不是首位，返回0
              return 0;
              flag = s =='-'? 1:0;//标记正负
            }
            else if (s>='0'&& s<='9')//将字符串转变成int类型
            {
                if(s=='0')
                {
                    if(sum==0)//前置零的情况特判；
                        return 0;
                    else
                        sum=sum*10+0;
                }
                else
                {
                    sum=sum*10 + s-'0';//转换int类型，
                    
                }
            }
           else
           {
               return 0;
           }
        }
        if(flag)
        {    //负数
            sum=-sum;
            if(sum<INT_MIN)//小于int最小值
                return 0;
            return sum;
        }
        else{ //正数
            if(sum>INT_MAX)//大于int最大值
                return 0;
            return sum;
         }
    }
};
