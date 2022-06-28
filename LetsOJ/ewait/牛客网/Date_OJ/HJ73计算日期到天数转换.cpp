//#define _CRT_SECURE_NO_WARNINGS 1
////HJ73 计算日期到天数转换
////https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//#include <iostream>
//using namespace std;
//
//int GetMonthDay(int year, int month)
//{//获取某月天数
//    int monthDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
//        return 29;
//    }
//
//    return monthDay[month];
//}
//
//
//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//    int sum = 0, j = 1;
//    while (j < month)
//    {
//        sum += GetMonthDay(year, j);
//        j++;
//    }
//    sum += day;
//    cout << sum;
//    return 0;
//}