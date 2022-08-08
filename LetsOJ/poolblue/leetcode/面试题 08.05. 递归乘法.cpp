//https://leetcode.cn/problems/recursive-mulitply-lcci/
//面试题 08.05. 递归乘法
class Solution {
public:
// 1、思路
// 先找出两个数中较大的数big和较小的数 small，helper()方法的作用是计算big与small的乘积，我们用一个变量halfProd来保存big与small乘积的一半；
// 若small为偶数，则直接将halfProd加倍返回即可，若small为奇数，则在halfProd加倍的基础上再返回一个big；
// 每次递归相当于将small除以2，同时将big乘以2；
// 时间复杂度为 O(s) ， s 表示两个数中较小的那个。

    int _multiply(int small,int big)
    {
      if(small==0)
      return 0;
      if(small==1)
      return big;

      int s=small>>1;
      int halfprod=multiply(s,big);

      if(small%2==0)
      return halfprod +halfprod;
      else
      return halfprod+halfprod+big;

    }
    int multiply(int A, int B) {
    int small = A < B? A :B;
    int big   = A < B? B :A;
   return _multiply(small,big);
     
    }
    
};
