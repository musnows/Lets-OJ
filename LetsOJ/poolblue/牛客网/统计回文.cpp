//统计回文
#include<iostream>
using namespace std;
bool  ispalindrome(string str)
{   //双指针判断回文
    int left=0;
    int right=str.size()-1;
    while(left<right)
    {
        if(str[left]!=str[right])
            return false;
        ++left;
        --right;
    }
    return true;
}
int main()
{
    string str1,str2,tmp;
    cin>>str1>>str2;
    tmp=str1;//将str1的字符串备份
    int len=str1.size()+1;
    int count=0;
    for(int i=0;i<len;i++)
    {
        str1=tmp;//每次插入字符串时，还原str1字符串
        str1.insert(i,str2);
        if(ispalindrome(str1))//判断插入后是否回文
        {
            count++;//计数
        }
    }
    cout<<count<<endl;
    return 0;
} 
