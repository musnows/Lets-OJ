//https://www.nowcoder.com/practice/af2c953f9fc8464fa0e3252da8eb4131?tpId=182&&tqId=34861&rp=1&ru=/ta/exam-all&qru=/ta/exam-all/question-ranking
//OR135 单词缩写
#include<iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(s.size()>=10)
        { 
           int len=s.size()-2;//计算长单词缩写字数
           string first=s.substr(0,1);//取出首字符
           string end=s.substr(s.size()-1,1);//取出尾字符
           s.erase(0);//删除原字符
           s+=first;//将首字符尾插
           s+= to_string(len);//尾插缩写字数
           s+=end;//将尾字符尾插
        }
        cout<<s<<endl;
    }
    return 0;
}