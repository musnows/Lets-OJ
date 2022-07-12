//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
////KY222 打印日期
////https://www.nowcoder.com/practice/b1f7a77416194fd3abd63737cdfcf82b?tpId=69&&tqId=29669&rp=1&ru=/activity/oj&qru=/ta/hust-kaoyan/question-ranking
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
//int main()
//{
//    int year, month, day;
//    int n;
//    while (scanf("%d %d", &year, &n) != EOF)
//    {
//        int sum = 0;
//        for (int i = 1; i <= 12; i++) {
//            sum += GetMonthDay(year, i);
//            if (n <= sum)
//            {
//                month = i;
//                sum -= GetMonthDay(year, i);//复原sum
//                break;
//            }
//        }
//        day = n - sum;
//        //cout << year << "-" << month << "-" << day << endl;
//        printf("%04d-%02d-%02d", year, month, day);
//    }
//
//
//    return 0;
//
//
//}