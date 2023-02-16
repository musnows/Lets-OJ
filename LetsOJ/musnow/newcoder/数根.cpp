// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
//https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
//出题人用例是string都不说清楚
//让别人猜？有意思吗


// 计算数根
int numRoot(int temp)
{
    int sum=0;
    while(temp)
    {
        sum+=temp%10;
        temp/=10;
    }
    return sum;
}

int main()
{
    string s;
    while(cin>>s)
    {
        if(s.size()>=2)
        {
            int sum=0;
            for(auto&e:s)
            {
                sum+=(e-'0');
            }
            while(sum>=10)
            {
               sum=numRoot(sum);
            }
            cout << sum << endl;
        }
        else
        {
            cout << s<<endl;
        }
    }
}
    



// 出题人输入的是string！！！压根不说清楚，什么人啊？
// int main()
// {
//     long long n;
//     while(cin>>n)
//     {
//         long long ret = n;
//         while(ret>=10)//一直计算直到为个位数
//         {
//             ret=numRoot(ret);
//         }
//         cout << ret << endl;
//     }
    
//     return 0;
// }
