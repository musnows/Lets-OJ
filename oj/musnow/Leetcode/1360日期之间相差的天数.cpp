class Solution {
    bool leap_year(int year) {
        if (year % 4 == 0 && year % 100 != 0) {
            return true;
        }
        if (year % 400 == 0) {
            return true;
        }
        return false;
    }
    // 日期转天数
    long date2int(const string& date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        static int monthDay[] = {0,  31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};
        long sum = day;
        while (month > 0) {
            month--; // 当前月还没有结束，不能算
            sum += monthDay[month];
            if (month == 2 && leap_year(year)) {
                sum += 1; // 二月闰年29天
            }
        }

        // 先加上基本年
        sum += 365 * (year - 1971);
        // 加上所有闰年(当前年不能算)
        sum += (year - 1) / 4 - 1971 / 4;     // %4为0的情况
        sum -= (year - 1) / 100 - 1971 / 100; // 减去%4为0但是%100为0的情况
        sum += (year - 1) / 400 - 1971 / 400; // 加上%400为0的情况
        return sum;
    }

public:
    int daysBetweenDates(string date1, string date2) {
        return abs(date2int(date1) - date2int(date2));
    }
};

//https://leetcode.cn/problems/number-of-days-between-two-dates/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china