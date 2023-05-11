#include <stdio.h>
#include <iostream>
using  namespace std;
int main()
{  //斐波那契数列就是左上角的数
    int fib[10000] = { 0,1,2 };//提前开好空间
    for (int i = 3; i < 10001; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];//生成斐波那契数列
        fib[i] %= 10000;//防止超过10000
    }
    int n = 0;
    while (cin >> n)
    {
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            printf("%04d", fib[num]);//取到相应左上角的数
        }
        printf("\n");
    }
    return 0;
}