#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int main() {

    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    string output("");
    if(s1.size()>s2.size())
        s1.swap(s2);//以短的字符串为前
    for(int i=0;i<s1.size();i++)//遍历两个字符串的所有字符串作为起始，然后同时开始检查字符是否相等，相等则不断后移，
                                 //增加子串长度，如果不等说明以这两个为起点的子串截止了，不会再有了，后续比较长度维护最大值即可。
    {
        for(int j=0;j<s2.size();j++)
        {
            int length=0;
            int x=i,y=j;
            while(x<s1.size() &&y<s2.size()&& s1[x]==s2[y])//找到最大子串区间
            {
                x++;
                y++;
                length++;
            }
            if(output.size()< length)//更新最大子串
            {
                output=s1.substr(i,x-i);
            }
        }
    }
    cout<<output<<endl;
    
   return 0;
}
