#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    while (cin >> num)
    {
        int ans = 0;
        for (int i = 0; i < num.size(); i++)
        {
            ans += num[i] - '0';//取每一位字符串数字转换成整数
        }
        int sum = 0;
        while (ans)//运算整根
        {
            sum += ans % 10;//取最低位
            ans = ans / 10;//将第二位置换到最低位
        }
        cout << sum << endl;
    }
    return 0;
}