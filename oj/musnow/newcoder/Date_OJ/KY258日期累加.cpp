//#include<iostream>
//using namespace std;
////ky258
////https://www.nowcoder.com/practice/eebb2983b7bf40408a1360efb33f9e5d?tpId=40&&tqId=31013&rp=1&ru=/activity/oj&qru=/ta/kaoyan/question-ranking
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
//    int n;
//    cin >> n;
//    while (n > 0)
//    {
//        int year, month, day, D;
//        cin >> year >> month >> day >> D;
//        day += D;
//        while (day > GetMonthDay(year, month))
//        {
//            day -= GetMonthDay(year, month);
//            month += 1;
//            if (month > 12) {
//                month = 1;
//                year++;
//            }
//        }
//        printf("%04d-%02d-%02d\n", year, month, day);
//        n--;
//    }
//    return 0;
//}