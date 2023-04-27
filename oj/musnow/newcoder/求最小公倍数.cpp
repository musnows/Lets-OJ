#include<iostream>
using namespace std;

int max_common_multiple(int a,int b)
{
    if(a<b){
        int t = a;
        a=b;
        b=t;
    }
    while(a%b){
        int temp = a;
        a = b;
        b = temp %b;
    }
    return b;
}

int main()
{
    int m,n;
    cin >> m >> n;
    cout << m*n/max_common_multiple(m,n) <<endl;
    
    return 0;
}
