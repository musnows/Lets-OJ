nclude<iostream>
#include<stack>
using namespace std;

int main()
{
    char n;
    stack<char> s;
    string str;
    getline(cin, str);
    for(auto&e:str)
    {
        s.push(e);
    }
    
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}
