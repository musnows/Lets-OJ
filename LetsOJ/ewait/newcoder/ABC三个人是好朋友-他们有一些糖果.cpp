#include <iostream>
using namespace std;

//题目要求：通过A+B B+C A-B B-C计算出ABC分别的值
//保证ABC都是整数
//如果不存在这样的整数ABC（比如浮点数）那就输出No

int main()
{
    int ab,bc,ba,cb;
    cin >> ab>>bc>>ba>>cb;
    int A = (ab+ba)/2;
    int B = (bc+cb)/2;
    int C = cb-B;
    if((A-B==ab)&&(A+B==ba)&&(B-C==bc)&&(B+C==cb))
    {
        printf("%d %d %d\n",A,B,C);
    }
    else{
        cout<<"No"<<endl;
    }
    
    
    return 0;
}