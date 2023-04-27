#include <iostream>
#include <string>
using namespace std;
int main() {
   string s1;
   string s2;
   while(cin>>s1>>s2)
   {    int count=0;//计数
       if(s1.size()==s2.size())//当字符串的长度相等时，要替换
       {
           for(int i=0;i<s2.size();i++)
           {
               if(s1[i]!=s2[i])
               {
                    s1[i]=s2[i];//直接替换
                     count+=2;//替换等于增删各一次，
               }
           }
       }
       else//当字符串的长度不相等时，要增删
       {
           if(s1.size()>s2.size())//当原字符串大于新字符串时，要删除
           {
               for(int i=0;i<s1.size();i++)
               {
                   if(s1[i]!=s2[i])
                   {
                       s1.erase(i,1);
                       count++;//删除计数
                   }       
               }
           }
           else//当原字符串小于新字符串时，要增加
           {
               for(int i=0;i<s2.size();i++)
               {
                   if(s1[i]!=s2[i])
                   {
                      s1.insert(i, 1, s2[i]);
                       count++;//增加计数
                   }
               }
           }
       }
       cout<<count<<endl;
   }
    return 0;
}
