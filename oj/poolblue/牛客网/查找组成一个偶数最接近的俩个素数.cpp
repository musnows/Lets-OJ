//https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//本题首先需要判断素数，素数表示除过1和本身，不能被其它数整除。通过循环遍历来判断一个数是否为素数。最近的两个素数应该从最中间的位置开始向两边查找。
#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
             return false;
        }
    }
    return true;
}
int main() {
    int num;
    while (cin >> num) {
       for(int i=num/2;i>=0;i--)
       {
        if(is_prime(i)  && is_prime(num-i))
        {
            cout<<i<<endl<<num-i<<endl;
            break;
        }
       }
        
    }
    return 0;
}
 
