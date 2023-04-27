//https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce
#include<iostream>
using namespace std;
#define PAI 3.14
int main()
{
    double n,r;
    while(cin>>n>>r)
    {
        double c =2.0*r*PAI;//碗的周长
        if(c<n)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
