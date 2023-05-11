//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int inf = 1e9;//初始化、无穷大
     int minPrice=inf;//不可初始化为0，可能第一个元素比0大或大很多
     int maxProfit=0;
     for(int i=0;i<prices.size();i++)//一次遍历
     {
        maxProfit=max(maxProfit,prices[i]-minPrice);//对比今天的价格是不是最大利润
        minPrice=min(prices[i],minPrice);//继续找最小值
       
     }
     return maxProfit;
    }
}; 
