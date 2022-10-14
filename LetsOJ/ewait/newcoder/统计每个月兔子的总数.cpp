#include<iostream>
#include<vector>
using namespace std;

int fib(int n)
{
    if(n<=2){
        return 1;
    }
    
    return fib(n-1)+fib(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    
    return 0;
}
//一月份有1只兔子，兔子张到“第”三月后，每个月生一个兔子
//一只兔子第三月出生，长到第五月后每一个月生一个兔子

//看着很麻烦，其实就是个斐波那契数列
