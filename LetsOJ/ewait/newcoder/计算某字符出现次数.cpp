#include<iostream>
#include<string>
using namespace std;

bool isWords(const char& c)
{
    return (c>='A'&&c<='Z')or(c>='a'&&c<='z');
}

int main()
{
    string s;
    getline(cin, s);
    char c;
    cin >> c;
    int count = 0;
    for(auto&e:s)
    {
        if(e==c){
            count++;
        }
        else if(isWords(c) and isWords(e))
        {
            if((e+32)==c or (e-32)==c)
            {
                count++;
            }
        }
    }
    cout << count << endl;
    
    return 0;
}

//如果是d字母，不区分大小写
//需要保证e和c都是字母的时候，在判断大小写字母对应问题
//用例输入一个字符串
//在输入一个字符
//输出z该字符在字符串中的个数
