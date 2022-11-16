//https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            continue;
        }
        int count = 0;
        while (n >= 2) {
            ++count;
            if (n % 3) {
                //不可以整除则取最差情况：特别的一份是 n/3 + 1个金币
                n = n / 3 + 1;
            }
            else {
                //可以整除在直接整除，能够获取到一份
                n /= 3;
            }
        }
        cout << count << endl;
    }
    return 0;
}