// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n;
    vector<string> v;
    while(cin>>n)
    {
        v.resize(n);
        getchar();//吃掉回车，否则会少接收一个字符串
        for(int i=0;i<n;i++)
        {
            getline(cin,v[i]);
        }
        for(int i=0;i<n;i++)
        {
            //auto it = v[i].find(",");
            if(v[i].find(",")!=string::npos)
            {
                cout<<"\"" << v[i] << "\"";
            }
            else if(v[i].find(" ")!=string::npos)
            {
                cout<<"\"" << v[i] << "\"";
            }
            else
            {
                cout << v[i];
            }
            
            //判断是否为结尾
            if(i==n-1)
            {
                cout<<endl;
            }
            else
            {
                cout << ", ";
            }
        }
        
    }
}
