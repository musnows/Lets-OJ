#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//给定一个256字符的字符串，输出内部最长数字子串
bool isNumStr(const char& c)
{
    return (c >= '0' && c <= '9');
}

int main()
{
    string s;//来源
    while(getline(cin, s))
    {
        //cout<<s<<endl;
        //string ret_s;//结果
        vector<pair<int,int>> v;//用来存放数字子串的位置
        int begin = 0;//标记数字串的开始
        int count = 0;//标记长度
        int max = 0, mbegin;//上一次获取到的数据串长度和起始位置
        int flag = 0;//标记位
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && isNumStr(s[i]) && isNumStr(s[i + 1]))
            {
                count++;
                if (flag != 1) {
                    begin = i;//说明开始计算了
                    flag = 1;
                }
                //cout<<"i"<<i<<" c"<<count<<" b"<<begin<<endl;
            }
            else if (isNumStr(s[i]))//自己还是数字，但是下一位不是
            {
                count++;
                //cout<<"i"<<i<<" c"<<count<<" b"<<begin<<endl;
            }
            else {
                if (count >= max) {
                    max = count;//最大的长度
                    mbegin = begin;//最大长度的起始位置
                    v.push_back(make_pair(count, begin));
                }
                count = 0;//置零
                flag = 0;
            }

        }

                    
        if (count >= max)
        {//循环结束后还需要一次判断，避免最后一个字符依旧是数字的情况
            max = count;
            mbegin = begin;
            v.push_back(make_pair(count, begin));
        }
        
        for(auto e:v)
        {
            if(e.first==max)
            {
                for(int i = e.second;i<e.second+e.first;i++)
                {
                    cout<<s[i];
                }
            }
        }
        cout<<","<<max<<endl;//结束后统一输出max
    }

    return 0;
}
// 通过全部用例  运行时间4ms 占用内存448KB
//HJ92 在字符串中找出连续最长的数字串
//https://www.nowcoder.com/practice/2c81f88ecd5a4cc395b5308a99afbbec?tpId=37&tqId=21315&ru=/exam/oj