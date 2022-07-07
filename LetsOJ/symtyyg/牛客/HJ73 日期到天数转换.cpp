//https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;

int main()
{
	int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;
	cin >> year >> month >> day;

	int n = days[month - 1] + day;
	if (month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
	{
		n += 1;
	}
	cout << n << endl;
	return 0;
}