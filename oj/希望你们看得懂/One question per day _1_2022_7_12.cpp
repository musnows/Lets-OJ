One question per day _1_2022_7_12
#include <iostream>
using namespace std;

int mon[12]={0,31,59,90,120,151,181,212,243,273,304,334};
bool isLeapYear(int year)
{
    if((year % 4 == 0) && (year % 100 != 0)||(year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Countday(int y,int m,int d)
{
    int yearday = y*365 + y/4 - y/100 + y/400;
    int monthday = mon[m - 1];
    if(m > 2 && isLeapYear(y))
    {
        monthday + 1;
    }
    return yearday + monthday + d;
}
int main()
{
    int year1,year2;
    int month1,month2;
    int day1,day2;
    scanf("%4d%2d%2d",&year1,&month1,&day1);
    scanf("%4d%2d%2d",&year2,&month2,&day2);
    int n1 = Countday(year1,month1,day1);
    int n2 = Countday(year2,month2,day2);
    int ret = abs(n1 - n2) + 1;
    cout << ret << endl;
    return 0;
}