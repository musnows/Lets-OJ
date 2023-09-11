//https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking 
#include iostream
#include string
using namespace std;

int main()
{
     注意这里不能使用cin接收，因为cin遇到空格就结束了。 
     oj中IO输入字符串最好使用getline。
    string str1,str2;
    getline(cin,str1);
    getline(cin,str2);
    
     使用哈希映射思想先str2统计字符出现的次数
    int hash[256] ={0};
    for(int i=0;istr2.size();i++)
    {
        hash[str2[i]]++;
    }
     遍历str1，str1[i]映射hashtable对应位置为0，则表示这个字符在 
     str2中没有出现过，则将他+=到ret
    string ret;
    for(int i=0;istr1.size();i++)
    {
        if(hash[str1[i]] == 0)
        {
            ret += str1[i];
        }
    }
    cout retendl;
    return 0;
}


