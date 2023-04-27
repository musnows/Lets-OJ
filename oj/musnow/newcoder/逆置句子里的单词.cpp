#include<iostream>
using namespace std;
//逆置单词，不倒置标点
//I like beijing.
//beijing. like I
int main()
{
    string s1,s2;
    cin>>s1;
    while(cin>>s2)
    {
        s1= s2+" "+s1;
    }
    cout<<s1;
    
    return 0;
}