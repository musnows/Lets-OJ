#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        if((a+b)>c && (a+c)>b && (c+b)>a)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
//https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
