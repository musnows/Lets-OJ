//https://leetcode.cn/problems/third-maximum-number/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
   long long firstnum=LONG_MIN,secondnum=LONG_MIN,thirdnum=LONG_MIN;
   //firstnum为最大,secondnum为第二大，thirdnum为第三大 
   
   for(auto&n :nums)//遍历 
   {
       if(firstnum < n)//如果比第一大还大，取代第一大，把原来最大的放在第二大 
       {
            thirdnum=secondnum;
            secondnum=firstnum;
            firstnum=n;
       }
       else if(firstnum > n && n >secondnum)//同理，取代第二大，原第二大递推第三大 
       {
           thirdnum=secondnum;
           secondnum=n;
       }
       else if(secondnum >n && n>thirdnum)//只大于第三大，取代第三大 
       {
           thirdnum=n;
       }
   }
   if(thirdnum!=LONG_MIN)//如果有第三大，返回第三大 
   return thirdnum;
   else
   return firstnum;//没有返回第一大 
    }
}; 
