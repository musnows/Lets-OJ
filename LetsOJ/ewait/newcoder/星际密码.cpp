// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

//不能用递归，内存超限
// int fib(int a)
// {
//     if(a<=2)
//     {
//         return 1;
//     }
//     return fib(a-1)+fib(a-2);
// }
#define SIZE 10001
int main()
{
    //初始化一个斐波那契数列
    vector<int> v;
    v.resize(SIZE);
    v[0]=v[1]=v[2]=1;
    for(int i=2;i<=SIZE;i++)
    {//因为结果只需要后四位，所以必须取模10000，否则打印出来的结果错误
        v[i]=(v[i-1]+v[i-2])%10000; 
    }
    // 获取输入
    int n;
    while(cin>>n)
    {
        int a;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            printf("%04d",v[a]);
        }
        cout << endl;
    }
    
    return 0;
}
//https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
