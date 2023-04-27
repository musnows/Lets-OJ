#include <iostream>
#include <string>
#include <vector>
using namespace std;

void DevideParams()
{
    string s;
    getline(cin, s);
    vector<string> v;
    int i =0,begin = 0;
    for(i=0;i<s.size()-1;i++)//这里小于sz-1是为了后面begin的+1
    {
        if(s[i]=='\"')//注意转义
        {
            size_t found = s.find('\"',i+1);//从i+1开始往后找下一个引号
            if(found!=string::npos)//找到了（其实不大可能找不到）
            {
                //i当前所在是左引号的位置
                //i+1去掉左引号
                //found-i是原本左引号到右引号字符串的长度，因为i+1了
                //所以字符串长度需要-1，不然就会把右引号纳入
                v.push_back(string(s,i+1,found-i-1));
            }
            if(found == s.size()-1)//右引号在末尾
            {
                break;
            }
            else{//更新区间，否则还会判断
                i = found +1;//跳过右引号后的括号
                //i当前所在位置是空格
                begin = i +1;//需要跳过空格
            }
        }
        else if(s[i]==' '){
            v.push_back(string(s,begin,i-begin));
            begin = i+1;//需要跳过空格
        }
    }
    if(i>=s.size()-1)//这种情况说明末尾不是右引号
    {
        v.push_back(string(s,begin,s.size()-begin));
    }
    cout << v.size() << endl;
    for(auto& e:v){
        cout << e << endl;
    }
}


int main()
{
    DevideParams();
    return 0;    
}
