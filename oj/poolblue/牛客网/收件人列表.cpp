#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n=0;
    while(cin>>n)
    {  getchar();// 注意：接收完第一行的整数之后，必须要再接收下该行之后的空格，无法直接获取下一行
        
        
        string name;
        for(int i=0;i<n;i++)//输入收件人名字
        {   
            
           getline(cin,name);
            names.push_back(name);
        }
        for(auto m:names)// 接收一个用例，当找到','或者‘ ’时候补双引号
                              // 否则：输出
        {
            if(m.find(',')!=string::npos|| m.find(' ') != string::npos)
                cout<<"\""<<m<<"\"";//使用转义字符打印双引号
            else
               cout<<m;
            if(m!=names.at(names.size()-1))// 注意：最后一个名字之后没有，
                cout<<", ";
        }
        cout<<endl;//换行
    }
  return 0;
}
