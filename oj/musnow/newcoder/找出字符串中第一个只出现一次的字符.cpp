#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i =0;
    map<char,pair<int,int>> m;
    for(i=0;i<s.size();i++)
    {
        if(m.find(s[i])==m.end())
        {
            m[s[i]]={i,1};//下标，次数
        }
        else
        {
            m[s[i]].second++;//次数++
        }
    }
    int first = s.size();//下标
    for(auto&e:m)
    {
        //cout << e.first << "-" << e.second << endl;
        if(e.second.second==1)
        {
            if(e.second.first < first){
                first=e.second.first;//下标
            }
        }
    }
    //cout << first << endl;
    if(first!=s.size())
    {
        cout << s[first] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    
    return 0;
}
