#include<iostream>
#include<stack>
using namespace std;
//十进制转n进制
//这里的负数判断只需要加上-就行，没有要求转成真的负数形式
//那样更加麻烦
const char base[]="0123456789ABCDEF";
void _str2n(int m,int n,stack<char>& s)
{
    if(m<=0){
        return;
    }
    int index=m%n;
    s.push(base[index]);
    
    _str2n(m/n,n,s);
}

int main()
{
    int m,n;
    cin >> m >> n;
    
    //需要处理负数
    if(m<0){
       m=-m;
        cout<<'-';
    }
    else if(m==0)
    {
        cout<<"0";
    }
    stack<char>s;
    _str2n(m,n,s);

    while(!s.empty())
    {    
        cout<<s.top();
        s.pop();
    }

    return 0;
}