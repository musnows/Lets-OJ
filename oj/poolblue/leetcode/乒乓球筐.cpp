//https://www.nowcoder.com/questionTerminal/bb4f1a23dbb84fd7b77be1fbe9eaaf32?f=discussion
//#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string s1;
    string s2;
    while(cin>>s1>>s2)
    {
       map<char,int> p1,p2;
        for(auto ch1:s1)
        {
           ++p1[ch1];
        }
        for(auto ch2:s2)
        {
           ++p2[ch2];
        }
       bool flag=true;
        for(auto p : p2)
        {
            if(p1[p.first] < p.second)
            {
                flag=!flag;
                break;
            }
         }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    
    return 0;
}