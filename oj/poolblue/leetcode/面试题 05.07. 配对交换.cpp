//https://leetcode.cn/problems/exchange-lcci/
//面试题 05.07. 配对交换 
class Solution {
public:
    int exchangeBits(int num) {
    //   奇数位全1 -> 0101.... 表示为 0x55555555
    //  偶数位全1 -> 1010.... 表示为 0xaaaaaaaa
    //   ans = (提取奇数位 << 1) + (提取偶数位 >> 1)
        return (((num & 0x55555555) << 1) | ((num & 0xaaaaaaaa) >> 1));

    }
};
