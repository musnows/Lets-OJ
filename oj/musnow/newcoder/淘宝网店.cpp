// write your code here cpp
#include<iostream>
#include<math.h>
using namespace std;

//返回当月日数
int GetMonthday(int y,int m)
{
    static int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((y%4==0&&y%100!=0)||(y%400==0))
    {
        if(m==2)
        {
            return 29;
        }
    }
    
    return day[m];
}
//判断素数
bool isPrimeN(int n)
{
    if(n==2)
    {
        return true;
    }
    else if(n==1)
    {
        return false;
    }
    
    for(int j=2;j<=sqrt(n);j++)
    {
        if(n%j==0)
        {
            return false;
        }
    }
    return true;
}
//计算利润
int CountProfit(int month,int diffDay)
{
    int sum=0;
    if(isPrimeN(month))
    {
        sum+=diffDay*1;
    }
    else
    {
        sum+=diffDay*2;
    }
    return sum;
}

int main()
{
    int year1,year2,month1,month2,day1,day2;
    while(cin>>year1>>month1>>day1>>year2>>month2>>day2)
    {
        int y1=year1,m1=month1,d1=day1;
        int y2=year2,m2=month2,d2=day2;
        int sum=0;
        int curM = m1;
        int curMday,diffDay;
        //其他
        while(y1!=y2 || m1!=m2)
        {
            curMday = GetMonthday(y1,m1);
            diffDay = curMday - d1 +1;
            sum+=CountProfit(m1, diffDay);
            d1=1;
            m1++;
            if(m1==13)
            {
                m1=1;
                y1++;
            }
        }
        //年月相同
        if(y1==y2 && m1==m2)
        {
            diffDay = d2-d1+1;
            sum+=CountProfit(m1, diffDay);
        }
        cout << sum << endl;
    }
    return 0;
}

//淘宝网店 牛客
//https://www.nowcoder.com/questionTerminal/754921e9c98b43d1b2d70c227b844101
