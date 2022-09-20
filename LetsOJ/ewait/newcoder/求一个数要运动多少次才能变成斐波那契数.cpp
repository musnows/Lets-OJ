#include <iostream>
using namespace std;

int fib(int n)
{
    if (n < 3)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int testFib(int n)
{
    int arr[34];
    for (int i = 1; i < 33; i++)
    {
        arr[i] = fib(i);
        arr[i + 1] = fib(i + 1);
        //cout<<arr[i]<<endl;
        if (n >= arr[i] && n <= arr[i + 1])
        {
            int m1 = abs(fib(i + 1) - n);
            int m2 = abs(arr[i] - n);
            //cout << m1 << " " << m2<< endl;
            return (m1 < m2 ? m1 : m2);
        }
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    cout << testFib(n) << endl;
    return 0;
}
//先把斐波那契数给算出来弄进数组（因为这道题的要求不高，n<1000000）
//然后直接判断即可
