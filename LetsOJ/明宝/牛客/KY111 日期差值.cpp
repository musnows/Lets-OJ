//https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&&tqId=29468&rp=1&ru=/activity/oj&qru=/ta/sju-kaoyan/question-ranking
//#define _CRT_SECURE_NO_WARNINGS 
//#include<iostream>
//#include<assert.h>
//using std::cin;
//using std::cout;
//using std::endl;
//
//class Date
//{
//public:
//	bool isLeapYear(int year)
//	{
//		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//	}
//	int GetMonthDay(int year, int month)
//	{
//		assert(year >= 0 && month >= 1 && month <= 12);
//		//优化：加static
//		static int monthDayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month == 2 && isLeapYear(year))
//		{
//			return 29;
//		}
//		return monthDayArr[month];
//	}
//
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		if (year >= 1
//			&& month <= 12 && month >= 1
//			&& day <= GetMonthDay(year, month) && day >= 1)
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			cout << "日期非法" << endl;
//		}
//	}
//
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			_month++;
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//		return *this;//this会被销毁，*this不会被销毁，可以直接传引用
//	}
//
//	bool operator!=(const Date& d) const
//	{
//		return _year != d._year || _month != d._month || _day != d._day;
//	}
//	bool operator<(const Date& d) const
//	{
//		return ((_year < d._year) || (_year == d._year && _month < d._month) || (_year == d._year && _month == d._month && _day < d._day));
//	}
//	int operator-(const Date& d) const
//	{
//		Date max = *this;
//		Date min = d;
//		int flag = 1;
//		if (max < min)
//		{
//			min = *this;
//			max = d;
//			flag = -1;
//		}
//
//		int n = 0;
//		while (min != max)
//		{
//			min+=1;
//			++n;
//		}
//		return n+1 ;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	int a = 0, b = 0;
//	cin >> a >> b;
//	int a3 = a % 100;
//	int a2 = a / 100 % 100;
//	int a1 = a / 10000;
//	int b3 = b % 100;
//	int b2 = b / 100 % 100;
//	int b1 = b / 10000;
//	Date d1(a1, a2, a3);
//	Date d2(b1, b2, b3);
//	cout << d1 - d2 << endl;
//	return 0;
//
// 
/////////////////////////////////////////////////////////////////////////////////////
//计算计算距离0000年0月1日的天数和，之后算差值的绝对值
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<iostream>
using namespace std;
int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
//给出年月日，计算距离0000年0月1日的天数和

int CountDay(int y, int m, int d)
{
	// 计算0-y年的天数
	int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
	// 计算到0-m月的天数
	int monthDay = mon[m - 1];
	if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		monthDay += 1;
	return yearDay + monthDay + d;

}

int main()
{
	int year1, month1, day1;
	scanf("%4d%2d%2d", &year1, &month1, &day1);
	int n1 = CountDay(year1, month1, day1);
	int year2, month2, day2;
	scanf("%4d%2d%2d", &year2, &month2, &day2);
	int n2 = CountDay(year2, month2, day2);
	cout << abs(n1 - n2) + 1 << endl;
	return 0;
}
