//https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
//来源：牛客网
//
//查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
//注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！
//
//数据范围：字符串长度1\le length \le300 \1≤length≤300 
//进阶：时间复杂度：O(n^3)\O(n 
//3
// ) ，空间复杂度：O(n)\O(n)


#include<iostream>
#include<string>
#include<string.h>
#include<map>
using namespace std;

int main()
{
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    //找出长短
    string maxS = s1.size()>=s2.size()?s1:s2;//大的那一个
    string minS = s1.size()<s2.size()?s1:s2;//小的那一个
    const char* cmp = minS.c_str();//获取小的字符串用于子串查找
    int begin=0,maxl=0,minB=0;
    multimap<int,int> retM;//用于存放键值对（需要支持冗余）
    for(int i =0;i<maxS.size()-1;i++)
    {
        for(int j =i+1;j<maxS.size();j++)
        {
            int len = j-i+1;
            string tmp = maxS.substr(i,len);
            const char* t1 = tmp.c_str();
            const char* ptr = strstr(cmp,t1);//查找子串
            if(ptr!=NULL && maxl<=len){
                begin = i;//这个是在maxS里面的起始位置
                maxl = len;//长度
                //在map里面的应该是在minS里面的起始位置，可以用指针相减得到
                minB=ptr-cmp;
                //cout <<"ptr-cmp" <<minB<<endl;
                retM.insert(make_pair(minB,len));
            }
        }
    }
    
    int a = maxl;//map中最长的串长度
    int minL = 0;//结果的长度
    minB = minS.size();
    //cout << "maxL " << a << endl;
    for (auto& e : retM)
    {
        //cout << e.first << "_" << e.second<<" ";
        if (e.second == a)//只有相同才进行操作
        {
            if (e.first < minB)//找出相同的begin最小的那一个（最先出现）
            {
                minB = e.first;
                minL = e.second;
                //cout << minB << "-" << minL << " ";
            }
        }
    }
    //cout << endl;
    //cout << "minB " << minB << " minL " << minL << endl;
    string ret2(minS, minB, minL);
    cout << ret2 << endl;
    
    return 0;
}