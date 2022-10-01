#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count =0;
    for(int i = 1;i<=n;i++)
    {
        int sum = 0;
        for(int j = 1;j < i;j++)
        {
            if(i%j == 0){
                sum +=j;
            }
        }

        if(sum == i){
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}
//完全数：它的所有真因子（除了自己以外的约数）的和等于它本身
//给定n，输出n以内包括n的完全数的数量
