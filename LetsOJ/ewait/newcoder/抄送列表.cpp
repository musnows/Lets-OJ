// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s1,s2;
    while(getline(cin,s1))
    {
        getline(cin,s2);
        vector<string>v;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]=='\"')
            {
                auto it = s1.find('\"',i+1);
                v.push_back(s1.substr(i+1,it-i-1));//计算出长度
                i=it+1;
            }
            else   
            {
                //找不到代表到结束了
                auto its= s1.find(',',i);
                if(its==string::npos)
                {
                    v.push_back(s1.substr(i,s1.size()-i));
                    i=s1.size();
                }
                else
                {
                    v.push_back(s1.substr(i,its-i));
                    i = its;
                }
                
            }
        }
        auto ret = find(v.begin(),v.end(),s2);
        if(ret!=v.end())
        {
            cout << "Ignore" <<endl;
        }
        else
        {
            cout << "Important!" <<endl;
        }
    }
    return 0;
}
//https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800

//我自己写的思路有问题，想走捷径，发现直接判断其实比拆开更麻烦
