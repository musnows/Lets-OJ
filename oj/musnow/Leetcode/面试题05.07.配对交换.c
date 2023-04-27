//面试题 05.07. 配对交换
//https://leetcode.cn/problems/exchange-lcci/
//交换一个整数二进制的奇偶位置
int exchangeBits(int num)
{
    int a = 0B10101010101010101010101010101010;
    int b = 0B01010101010101010101010101010101;
    a &= num; //保留奇数位
    b &= num; //保留偶数位
    a >>= 1;  //交换奇偶位
    b <<= 1;
    int ans = a | b;//分别将奇偶位组合在一起就可以
    return ans;
}
