 
#include <iostream>
using namespace std;

int main() {
    int f;
    int f1=0;
    int f2=1;
    int n;
    while (cin >> n) { 
        int left=0;
        int right=0;
       while(1)
       {
           f=f1+f2;
           f1=f2;
           f2=f;
           if(f<n)
           {
               left=f;//左边的fib数
           }
           else
           {
               right=f;//找到右边的fib数并跳出循环
               break;
           }
       }
       cout<<min(n-left,right-n)<<endl;
        
    }
    return 0;
}

