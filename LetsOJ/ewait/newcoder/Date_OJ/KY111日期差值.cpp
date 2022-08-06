//#define _CRT_SECURE_NO_WARNINGS 1
////KY111 日期差值
////https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&&tqId=29468&rp=1&ru=/activity/oj&qru=/ta/sju-kaoyan/question-ranking
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
//bool isMax(int y1, int m1, int d1, int y2, int m2, int d2)
//{
//    if (y1 > y2) {
//        return true;
//    }
//    else if (y1 = y2)
//    {
//        if (m1 > m2)
//            return true;
//        else if (m1 == m2)//月相等比较日期即可
//            if (d1 > d2) {
//                return true;
//            }
//            else {
//                return false;
//            }
//        else//年相等，月小了
//            return false;
//    }
//    else {
//        return false;
//    }
//    return false;
//}
//
//void Swap(int& a, int& b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}
//
//int main()
//{
//    int year1, month1, day1;
//    int year2, month2, day2;
//    int number, num1, num2;
//    while (scanf("%04d%02d%02d\n%04d%02d%02d", &year1, &month1, &day1, &year2, &month2, &day2) != EOF)
//    {
//        int flag = 1;
//        if (!isMax(year1, month1, day1, year2, month2, day2)) {
//            Swap(year1, year2);
//            Swap(month1, month2);
//            Swap(day1, day2);
//        }
//        int sum = 0;
//        while (!((year1 == year2) && (month1 == month2)))
//        {
//            month1--;
//            if (month1 == 0)
//            {
//                month1 = 12;
//                year1--;
//            }
//            sum += GetMonthDay(year1, month1);
//        }
//        int D = day1 - day2;//天数差距
//        sum += D;
//
//        //题目要求：有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//        sum++;//题目要求的补一天
//        
//        cout << sum << endl;
//    }
//
//    return 0;
//}