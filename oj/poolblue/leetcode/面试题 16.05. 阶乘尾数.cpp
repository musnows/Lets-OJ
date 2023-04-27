//https://leetcode.cn/problems/factorial-zeros-lcci/
//面试题 16.05. 阶乘尾数 
class Solution {
public:
    int trailingZeroes(int n) {
//求一个数的阶乘中有多少个 尾数0 ，尾数0 是乘以 10 来的，而 10=2*5 ，阶乘中 2 这个因子很多，但是 5 并不多，因此我们只需要统计 5 出现了多少次即可
//以 10 的阶乘为例 10!=1*2*3*4*5*6*7*8*9*10 ，每 5 个数字就会出现一次 5 ，所以 10 / 5 就是 5 出现的次数。其中包含多个 5 的， 25=5*5， 125=5*5*5,只被统计了一次,需要再次除以 5 ，得到剩余 5 的个数，直到最后结果小于 5 为止
    int count=0;
    while(n>=5)
    {
      count+=n/5;
      n/=5;
    }
     return count;
    }
   
};
