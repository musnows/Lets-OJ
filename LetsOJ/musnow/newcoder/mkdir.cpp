// write your code here cpp
#include<string>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string sbase =  "mkdir -p ";
    int n;
    while(cin>>n)
    {
        vector<string> v;
        v.resize(n);
        for(int i=0;i<v.size();i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());//排序保证结果输出的顺序
        vector<bool> flag(n,true);//初始化成n个true
        for(int i=0;i<v.size()-1;i++)
        {
            string tmp = v[i];
            tmp.push_back('/');
            if(v[i]==v[i+1])//两串相同
            {
                flag[i] = false;
            }
            else if(strstr(v[i+1].c_str(),tmp.c_str())!=nullptr)
            {//tmp在后一串中，代表是一个子目录
                flag[i] = false;
            }
            
        }
        for(int i=0;i<v.size();i++)
        {
            if(flag[i])
            {
                cout << sbase << v[i] << endl;
            }
        }
        cout<<endl;
        
    }
    return 0;
}
//https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a
