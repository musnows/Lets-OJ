//https://www.nowcoder.com/practice/fe6c73cb899c4fe1bdd773f8d3b42c3d?tpId=49&&tqId=29329&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking 
#include <iostream>
#include <vector>
using namespace std;
int GCD(int a,int b)
{
    //辗转相除法
    int c;
    while(c=a%b)
    {
        a = b;
        b = c;
    }
    return b;
}
 int GetPower(int n,int a)
{  vector<int> num(n);
   for(int i=0;i<n;i++)
   {
        cin>>num[i];//输入敌人的防御值
   }

   for(int i=0;i<n;i++)
   {
      if(a >= num[i])
          a+=num[i];
      else
        a+=GCD(a,num[i]);
   }
   return a;
}
int main() {
    int n, a;
    int power;
    while (cin >> n >> a) { 
        power=GetPower(n,a);
        cout<<power<<endl;
    }
}

