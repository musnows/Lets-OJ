#define _CRT_SECURE_NO_WARNINGS 1
//JZ64 求1+2+3+...+n
//https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include <iostream>
using namespace std;

//通过类的静态成员变量，和构造函数的特性
//每一次调用构造函数，count2从1开始加到n，然后count1++（这才能让count2从1+到n）
class Sum {
public:
    Sum()
    {
        count2 += count1;
        count1++;
    }
    static int Getcount()
    {
        return count2;
    }
private:
    static int count1;
    static int count2;
};
//静态成员吧变量需要通过类域来定义
int Sum::count1 = 1;
int Sum::count2 = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Sum* ptr = new Sum[n];//调用n次构造函数
        return Sum::Getcount();
    }

};