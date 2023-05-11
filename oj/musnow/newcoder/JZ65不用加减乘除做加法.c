/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param num1 int整型 
 * @param num2 int整型 
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
int Add(int num1, int num2) 
{
    while(num2)
    {
        int t = (num1 & num2) << 1;
        num1 ^= num2;
        num2 = t;
    }
    return num1;
}
//https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=23249&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//JZ65 不用加减乘除做加法
