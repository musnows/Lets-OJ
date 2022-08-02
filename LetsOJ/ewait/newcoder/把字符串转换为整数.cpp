//把字符串转换成整数
//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    bool isNumber(char c)
    {
        if(c>='0'&& c<='9')
            return true;
        if(c=='+'||c=='-')
            return true;
        
        return false;
    }
    int StrToInt(string str) {
        int num=0;
        int flag =1;//正负号
        
        auto it=str.rbegin();
        int j=0;
        while(it!=str.rend())
        {
            if(!isNumber(*it)){
                return 0;
            }
            else if(*it=='-'){
                flag=-1;
                it++;
            }
            else if(*it=='+'){
                flag=1;
                it++;
            }
            else{
                num+=(*it-'0')*pow(10,j);
                j++;
                it++;
            }
        }
        return num*flag;
    }
};