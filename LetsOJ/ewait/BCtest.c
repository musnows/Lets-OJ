#define _CRT_SECURE_NO_WARNINGS 1

//牛客网C语言入门刷题
//https://www.nowcoder.com/ta/beginner-programmers


//#include <stdio.h>
//bc001
//开始练习！2021.12.07
//int main()
//{
//    printf("Practice makes perfect!\n");
//    return 0;
//}

//#include <stdio.h>
////bc002
//int main()
//{
//	printf("v   v\n");
//	printf(" v v \n");
//	printf("  v  \n");
//	return 0;
//}

//#include <stdio.h>
////bc003
//int main()
//{
//
//	printf("The size of short is %d bytes.\n", sizeof(short));
//	printf("The size of int is %d bytes.\n", sizeof(int));
//	printf("The size of long is %d bytes.\n", sizeof(long));
//	printf("The size of long long is %d bytes.\n", sizeof(long long));
//	
//	return 0;
//}

//#include<stdio.h>
////新bc03
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    printf("%d", a);
//    return 0;
//}

//#include<stdio.h>
////新bc04
//int main()
//{
//    float a;
//    scanf("%f", &a);
//    printf("%.3f", a);
//    return 0;
//}


//
//#include <stdio.h>
////bc006-小飞机
//int main()
//{
//    printf("     **     \n");
//    printf("     **     \n");
//    printf("************\n");
//    printf("************\n");
//    printf("    *  *     \n");
//    printf("    *  *     \n");
//    return 0;
//}

//#include<stdio.h>
////新bc07
//int main()
//{
//    char a;
//    scanf("%c", &a);
//    printf("%c%c%c\n", a, a, a);
//    printf("%c%c%c\n", a, a, a);
//    printf("%c%c%c\n", a, a, a);
//    return 0;
//}


//#include <stdio.h>
////bc007
//int main()
//{
//    int a = 1234;
//    printf("%#o %#X", a, a);
//    return 0;
//}

//#include<stdio.h>
////新bc08
//int main()
//{
//    char a;
//    scanf("%c", &a);
//
//    printf("  ");
//    printf("%c\n", a);
//    printf(" ");
//    printf("%c%c%c\n", a, a, a);
//    printf("%c%c%c%c%c\n", a, a, a, a, a);
//    printf(" ");
//    printf("%c%c%c\n", a, a, a);
//    printf("  ");
//    printf("%c\n", a);
//    return 0;
//}

//#include <stdio.h>
////bc-008
//int main()
//{
//    int a = 0xABCDEF;
//    printf("%15d", a);
//    return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    float a = 0;
//    scanf("%f", &a);
//    //输入四舍五入后的整数部分
//    printf("%.0f", a);
//
//    return 0;
//}
//#include <stdio.h>
////bc09
//int main()
//{
//
//    int a = printf("Hello world!");
//    printf("\n");
//    printf("%d", a);
//
//    return 0;
//}


//#include <stdio.h>
////bc10
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    printf("score1=%d,score2=%d,score3=%d", a, b, c);
//    return 0;
//}

//#include <stdio.h>
////bc11
//int main()
//{
//    int a;
//    float b, c, d;
//    scanf("%d;%f,%f,%f", &a, &b, &c, &d);
//
//    printf("The each subject score of No. %d is %.2f, %.2f, %.2f.", a, b, c, d);
//    return 0;
//}//double类型不会四舍五入，但是float可以


//#include <stdio.h>
//bc12-打印圣诞树
//int main()
//{
//	char n;
//	scanf("%c", &n);//输入字符
//
//	int m = 4;//空格个数，第一行4个
//
//	for (int i = 1; i <= 5; i++)
//	{
//		int j = 0;
//		for ( j = 0; j < m; j++)
//		{
//			printf(" ");
//		}
//		m--;//下一行少一个
//		for (int k = 0; k < i; k++)
//		{
//			printf("%c ", n);
//		}
//		printf("\n");
//		
//	}
//	return 0;
//}

//#include <stdio.h>
////bc13-ASCII
//int main()
//{
//	int arr[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116 , 33 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%c", arr[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
////bc14.输入一个人的出生日期（包括年月日），将该生日中的年、月、日分别输出
//
//int main()
//{
//	int year,month,date;
//	scanf("%4d%2d%2d", &year,&month,&date);
//	//通过scanf函数的% m格式控制可以指定输入域宽，输入数据域宽（列数），按此宽度截取所需数据
//	//%4d格式控制符，限制scanf截取4位放入指定变量
//	printf("year=%d\n", year);
//	printf("month=%02d\n", month);//%02d，两位，不够左补0
//	printf("date=%02d\n", date);
//
//	return 0;
//}

//#include <stdio.h>
////bc15-交换两个数并输出
//int main()
//{
//	//a=1,b=2
//	int a, b;
//	scanf("a=%d,b=%d", &a, &b);
//	int tmp=a;//交换
//	a = b;
//	b = tmp;
//	printf("a=%d,b=%d",a,b);
//	return 0;
//}

//#include<stdio.h>
////新bc15，交换大小写
//int main()
//{
//    char a;
//    while (scanf("%c", &a) != EOF)
//    {
//        getchar();//吞掉回车
//        char b = a + 32;
//        printf("%c\n", b);
//    }
//
//
//    return 0;
//}

//#include <stdio.h>
////bc16输出字符对应的ASCII码
//int main()
//{
//	char a = 0;
//	scanf("%c", &a);
//	printf("%d\n",a);
//
//	return 0;
//}

//#include<stdio.h>
////新BC16 十六进制转十进制
//int main()
//{
//    int a = 0xABCDEF;
//    printf("%15d\n", a);
//
//    return 0;
//}

//#include<stdio.h>
//
////bc17：计算(-8 + 22)×a - 10 + c÷2,其中，a = 40，c = 212。
//int main()
//{
//	int sum = 0;
//	int a = 40, c = 212;
//	sum = (22-8) * a-10+c/2;
//	printf("%d", sum);
//	return 0;
//}

//#include<stdio.h>
////bc18,输入a和b，计算a和b的商+余数
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//
//	printf("%d %d", a / b, a % b);
//
//	return 0;
//}

//#include <stdio.h>
////新BC17：10进制转8和16
//int main()
//{
//    int a = 1234;
//    printf("%#o %#X", a, a);
//    return 0;
//}
// 
//#include<stdio.h>
//BC18 牛牛的空格分隔
//int main()
//{
//    char a;
//    int b;
//    float c;
//    scanf("%c %d %f", &a, &b, &c);
//    printf("%c %d %f\n", a, b, c);
//
//
//    return 0;
//}
// 
//#include<stdio.h>
////bc19反向输出一个4位数
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n)
//	{
//		printf("%d", n % 10);
//		n /= 10;
//	}
//		
//	return 0;
//}

//#include<stdio.h>
////新BC19 牛牛的对齐
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    printf("%-8d%-8d%-8d\n", a, b, c);//靠右对齐需要加-
//
//    return 0;
//}
// 
//#include<stdio.h>
////bc20
////计算规则45+80=25,1234+10=34+10
//int main()
//{
//	int a, b;
//	int sum;
//	scanf("%d%d", &a, &b);
//
//	int a1, b1;
//	a1 = a % 10;
//	a /= 10;
//	a1 += a % 10 * 10;
//	b1 = b % 10;
//	b /= 10;
//	b1 += b % 10 * 10;
//
//	//printf("%d %d", a1, b1);
//	sum = a1 + b1;
//
//	int sum1 = 0;
//	sum1 = sum % 10;
//	sum /= 10;
//	sum1 += sum % 10 * 10;
//
//	//if (a <= 100 && b <= 100)
//	//{
//	//	sum = a + b;
//	//	if (sum >= 100&&sum!=200)
//	//	{
//	//		sum -= 100;
//	//	}
//	//	else if (sum == 200)
//	//	{
//	//		sum = 0;
//	//	}
//	//}
//
//	printf("%d", sum1);
//	return 0;
//}

//#include<stdio.h>
////新BC20 进制A+B
//int main()
//{
//    int a, b;
//    scanf("%x", &a);//输入十六进制，0x小写
//    scanf("%o", &b);//输入八进制数
//    int c = a + b;
//
//    printf("%d\n", c);
//
//    return 0;
//}

//#include<stdio.h>
////bc21浮点数的个位数字
//int main()
//{
//	float a = 0;
//	scanf("%f", &a);
//
//	int b= (int)a % 10;
//	printf("%d", b);
//	return 0;
//}

//#include<stdio.h>
////新BC21 牛牛学加法
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d\n", a + b);
//
//    return 0;
//}

//#include<stdio.h>
////BC22:一年约有 3.156×10^7 s，要求输入您的年龄，显示该年龄合多少秒
//int main()
//{
//	double f = 3.156E7;
//	double old = 0;
//	scanf("%lf", &old);
//	double s = old * f;
//	printf("%.0lf", s);
//
//	return 0;
//}

//#include<stdio.h>
////新BC22 牛牛学除法
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d\n", a / b);
//
//    return 0;
//}

//#include<stdio.h>
////BC23 给定秒数seconds，把秒转化成小时、分钟和秒
//int main()
//{
//	int s = 0;
//	scanf("%d", & s);
//
//	//s/60得到小时
//	//s%60得到余数，再÷60得到分钟
//
//	//3661: 1h 1m 1s
//	int seconds = s % 3600;
//	if (seconds >= 60)
//	{
//		seconds %= 60;
//	}
//	s -= seconds;//3660
//
//	int min = s/ 60;//61
//	if (min >= 60)
//	{
//		min %= 60;//1
//	}
//	s -= min * 60;//3600
//
//	int hour = s / 3600;
//	printf("%d %d %d\n", hour, min, seconds);
//
//	return 0;
//}

//#include<stdio.h>
////新BC23 牛牛学取余
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d\n", a % b);
//
//    return 0;
//}

//#include <stdio.h>
////bc24 依次输入一个学生的3科成绩，在屏幕上输出该学生的总成绩以及平均成绩
//int main()
//{
//	double a, b, c;
//	scanf("%lf%lf%lf", &a, &b, &c);
//
//	printf("%.2lf ", a + b + c);
//	printf("%.2lf\n", (a + b + c) / 3.0);
//
//	return 0;
//}

//#include<stdio.h>
////新BC24 浮点数的个位数字
//int main()
//{
//	float a = 0;
//	scanf("%f", &a);
//
//	int b = (int)a % 10;
//	printf("%d", b);
//	return 0;
//}

//#include<stdio.h>
////bc25 计算bmi
////用体重公斤数除以身高米数平方得出的数字
//int main()
//{
//	int weight, hight;//输入的是厘米身高
//	scanf("%d%d", &weight, &hight);
//
//	double h = hight / 100.0;//单位换算成m
//	double bmi = weight / (h * h);
//
//	printf("%.2lf", bmi);
//	return 0;
//}


//#include <stdio.h>
//#include <math.h>
////bc26 根据给出的三角形3条边a,b,c,计算三角形的周长和面积
////海伦公式，已知三条边长求面积
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d",&a,&b,&c);
//
//	double circumference = a + b + c;
//	double p = circumference / 2.0;//p是半周长
//	double area = sqrt(p*(p-a)*(p-b)*(p-c));
//
//	printf("circumference=%.2lf area=%.2lf\n", circumference, area);
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
////bc27计算球体体积
////其中球体体积公式为 V = 4 / 3 * πr^3，其中 π = 3.1415926。
//int main()
//{
//	double pai = 3.1415926;
//	int r;
//	scanf("%d", &r);
//
//	double v = 4.0 / 3.0 * pai * pow(r, 3);
//	printf("%.3lf",v);
//	return 0;
//}



//————————————————————————
//————————————————————————


///22.03.05发现bc140题目进行了改版，细分了大类，题号也变了
//从运算那一章的BC25开始重新刷题！

//BC25 牛牛买电影票
//#include<stdio.h>
//
//int main()
//{
//    int x;
//    scanf("%d", &x);
//
//    printf("%d\n", x * 100);
//    return 0;
//}

//BC26计算带余除法
//#include<stdio.h>
//
//int main()
//{
//    int a, b;
//    scanf("%d%d", &a, &b);
//
//    printf("%d %d", a / b, a % b);
//
//    return 0;
//}

//BC27 整数的个位
//#include <stdio.h>
//
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    printf("%d", a % 10);
//    return 0;
//}

//BC28 整数的十位
//#include <stdio.h>
//
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    a /= 10;//123得到3
//    printf("%d", a % 10);
//    return 0;
//}

//BC29 开学？
//#include <stdio.h>
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    b %= 7;
//    int c = a + b;
//    if (c == 7)
//    {
//        printf("%d", c);
//        return 0;
//    }
//    else
//    {
//        c %= 7;
//        printf("%d", c);
//    }
//
//    return 0;
//}


//BC30 时间转换
//#include<stdio.h>
//
//int main()
//{
//    int time;
//    scanf("%d", &time);
//    int h = time / 3600;
//    time %= 3600;
//    int m = time / 60;
//    time %= 60;
//    int s = time % 3600;
//    printf("%d %d %d\n", h, m, s);
//
//    return 0;
//}

//22.04.02
//把BC25前面的新题也给写完了（主要想把进度刷成100%）


//#include<stdio.h>
////#include<math.h>
//
////BC31 2的n次方计算
////不使用累计乘法的基础上，通过移位运算（<<）实现2的n次方的计算。
//int main()
//{
//    int a;
//    scanf("%d", &a);
//    int b = 1 << a;
//    printf("%d\n", b);
//
//    return 0;
//}

//#include<stdio.h>
////BC32 你能活多少秒
//int main()
//{
//	long long s = 0;
//	scanf("%lld", &s);
//
//	printf("%lld\n", s * 31560000);
//
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
////BC33 统计成绩
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    float max = 0;
//    float min = 100;
//    float sum = 0;
//    float* arr = (float*)calloc(n, sizeof(float));
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%f ", &arr[i]);
//
//        if (arr[i] >= max)
//            max = arr[i];
//
//        if (arr[i] <= min)
//            min = arr[i];
//
//        sum += arr[i];
//    }
//    printf("%.2f %.2f %.2f\n", max, min, sum / n);
//
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
////BC34 计算三角形的周长和面积
////海伦公式，已知三条边长求面积
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//
//	double circumference = a + b + c;
//	double p = circumference / 2.0;//p是半周长
//	double area = sqrt(p * (p - a) * (p - b) * (p - c));
//
//	printf("circumference=%.2lf area=%.2lf\n", circumference, area);
//	return 0;
//}


//#include<stdio.h>
////BC35 KiKi和酸奶
//int main()
//{
//    int n, h, m;
//    scanf("%d %d %d", &n, &h, &m);
//
//    int drink = m / h;
//    if (m % h != 0)//如果不为0，说明有已经打开过还没喝完的
//        drink++;
//
//    int left = n - drink;
//    printf("%d\n", left);
//
//    return 0;
//}


//#include<stdio.h>
////BC36 温度转换
////float不行，double可以
//int main()
//{
//    double f = 0;
//    scanf("%lf", &f);
//
//    double c = 5.0 / 9.0 * (f - 32);
//    printf("%.3lf\n", c);
//
//    return 0;
//}

//#include<stdio.h>
////BC37 牛牛的圆
//int main()
//{
//    double r = 0;
//    double pai = 3.14;
//    scanf("%lf", &r);
//
//    printf("%.2lf\n", pai * r * r);
//
//    return 0;
//}

//#include<stdio.h>
////BC38 牛牛的并联电路
////求两个电阻并联后等效电阻是多少
//int main()
//{
//    double r1 = 0;
//    double r2 = 0;
//    scanf("%lf %lf", &r1, &r2);
//
//    printf("%.1lf\n", 1 / ((1.0 / r1) + (1.0 / r2)));
//
//    return 0;
//}

//#include<stdio.h>
////BC39 牛牛的水杯
////要喝10升水才能解渴，但现在只有一个深 h 厘米
////底面半径是 r 厘米的水杯，牛牛最少要喝多少杯水才能解渴。
//int main()
//{
//    //10升的单位是分米
//    double r = 0;//单位厘米！
//    double h = 0;//单位厘米！
//    double pai = 3.14;
//    scanf("%lf %lf", &h, &r);
//    h *= 0.1;//单位换算
//    r *= 0.1;
//    double v = pai * h * r * r  ;
//    double n = 10 / v;
//    int n1 = (int)n;
//    if ((n * 100 - (double)n1 * 100) != 0)
//        n1++;//判断小数点后是否有数
//
//    //printf("%.0lf\n", n);//四舍五入，err
//    printf("%d\n", n1);
//    return 0;
//}

//#include<stdio.h>
////BC40 牛牛的等差数列
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    int d = b - a;//求等差
//    int c = b + d;
//    printf("%d\n", c);
//    return 0;
//}

//#include<stdio.h>
//#include<math.h>
////BC41 牛牛的球
////牛牛有一个半径为 r 的球，他想知道这个球的体积。
//int main()
//{
//    double r = 0;
//    scanf("%lf", &r);
//    double pi = 3.14;
//    double v = (4.0 / 3) * pi * pow(r, 3);
//
//    printf("%.2lf\n", v);
//    return 0;
//}
//
//#include<stdio.h>
////BC42 小乐乐定闹钟
//
//// 输入现在的时刻以及要睡的时长k（单位：minute），中间用空格分开。
//// 输入格式：hour:minute k(如hour或minute的值为1，输入为1，而不是01)
//// (0 ≤ hour ≤ 23，0 ≤ minute ≤ 59，1 ≤ k ≤ 109)
////对于每组输入，输出闹钟应该设定的时刻，输出格式为标准时刻表示法
////（即时和分都是由两位表示，位数不够用前导0补齐）。
//int main()
//{
//    int h, m;
//    scanf("%d:%d", &h, &m);
//    int k = 0;
//    scanf("%d", &k);
//    int h1 = k / 60;
//    int m1 = k % 60;
//    h1 %= 24;//不考虑日期
//    h += h1;
//    m += m1;
//    if (m >= 60)
//    {
//        h++;
//        m %= 60;//防止相加后超出时间范围
//    }
//    if (h >= 24)
//        h %= 24;//防止相加后超出时间范围
//
//    printf("%02d:%02d", h, m);//两位，前导0，只有1位时补0
//    return 0;
//}

//#include<stdio.h>
////BC43 小乐乐排电梯
//
////小乐乐学校教学楼的电梯前排了很多人，他的前面有n个人在等电梯。电梯每次可以乘坐12人，每次上下需要的时间为4分钟（上需要2分钟，下需要2分钟）。
////请帮助小乐乐计算还需要多少分钟才能乘电梯到达楼上。（假设最初电梯在1层）
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    int m = 0;
//    if (n < 12)
//        m = 2;
//    else
//    {
//        m = (n / 12) * 4 + 2;
//    }
//
//    printf("%d", m);
//    return 0;
//}

//#include<stdio.h>
////BC44 小乐乐与欧几里得
////对于每组输入，输出一个正整数，为n和m的最大公约数与最小公倍数之和。
//long long Gcd(long long n, long long m)
//{
//    long long ret;
//    while (ret = n % m)
//    {
//        n = m;
//        m = ret;
//    }
//    return m;
//}
//
//int main()
//{
//    long long n, m, gcd, lcm, sum;
//    scanf("%ld %ld", &n, &m);
//
//    gcd = Gcd(n, m);
//    lcm = m * n / gcd;
//    sum = gcd + lcm;
//    printf("%ld\n", sum);
//    return 0;
//}

