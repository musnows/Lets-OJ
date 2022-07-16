//#define _CRT_SECURE_NO_WARNINGS 
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//int countDay(int year, int month)
//{
//	int count[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		count[2] = 29;
//	return count[month];
//}
//int main()
//{
//	int m = 0;
//	cin >> m;
//	while (m--)
//	{
//		int y = 0, m = 0, d = 0, n = 0;
//		cin >> y >> m >> d >> n;
//		d += n;
//		while (d > countDay(y, m))
//		{
//			d -= countDay(y, m);
//			++m;
//			if (m == 13)
//			{
//				m = 1;
//				++y;
//			}
//		}
//		printf("%04d-%02d-%02d\n", y, m, d);
//	}
//	return 0;
//}