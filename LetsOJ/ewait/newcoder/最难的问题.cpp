// write your code here cpp
#include<iostream>
#include<string>
#include<map>
using namespace std;




int main()
{
    string origin("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string code(  "VWXYZABCDEFGHIJKLMNOPQRSTU");
    map<char,char>m;
    for(int i=0;i<origin.size();i++)
    {
        //cout << code[i]<<'-'<<origin[i]<<endl;
        m[origin[i]]=code[i];
    }
    
    
    string s;
    while(getline(cin,s))
    {
        for(auto&e:s)
        {
            if(e<='Z'&&e>='A')
            {
                cout<<m[e];
            }
            else
            {
                cout<<e;
            }
        }
        cout <<endl;
    }
    
    return 0;
}
