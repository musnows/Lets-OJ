#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

int main()
{
    string num,fun;
    string f1 = "connect",f2="disconnect";
    int n;
    while(cin>>n)
    {
        //multimap<string,string> cnt_map;
        set<string> s;
        int max_sz=0,i;//要记得初始化
        for(i=0;i<n;i++)
        {
            cin>>num;
            cin>>fun;
            if(fun==f1)
            {
                s.insert(num);
                max_sz = (max_sz <= s.size())?s.size():max_sz;
            }
            else
            {
               s.erase(num);
            }
        }
        cout << max_sz << endl;
    }
    return 0;
}

//https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e
