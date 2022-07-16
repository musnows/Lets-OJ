////https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking
//
//#define _CRT_SECURE_NO_WARNINGS 
//#include<iostream>
//using namespace std;
////int main()
////{
////	int m = 0, n = 0;
////	while (scanf("%d%d", &m, &n) != EOF)
////	{
////		int arr[12] = { 31,59,90,120,151,181,212,243,273,304,334,365 };
////		if (n > 59 && (m % 4 == 0 && m % 100 != 0 || m % 400 == 0))
////		{
////			for (int i = 1; i < 12; i++)
////			{
////				++arr[i];
////			}
////		}
////		int j = 0;
////		while (n > arr[j])
////		{
////			j++;
////		}
////		int k = 0;
////		if (n < 31)
////			k = n;
////		else
////			k = n - arr[j - 1];
////		printf("%4d-%02d-%02d\n", m, j, k);
////	}
////	return 0;
////}
//
//int main()
//{
//	int year;
//	int day;
//	int mon[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31 };
//	while (cin >> year >> day)
//	{
//		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
//			mon[1] = 29;
//		else
//			mon[1] = 28;
//		for (int i = 0; i < 12; i++)
//		{
//			if (day <= mon[i])
//			{
//				printf("%04d-%02d-%02d\n", year, i + 1, day);
//				break;
//			}
//			else
//			{
//				day = day - mon[i];
//			}
//		}
//	}
//	return 0;
//}