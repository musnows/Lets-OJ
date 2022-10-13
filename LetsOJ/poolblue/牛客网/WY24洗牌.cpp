//https://www.nowcoder.com/practice/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0?tpId=122&tqId=33670&ru=/exam/oj
// WY24 洗牌
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int T;
    cin>>T;
    int n=0,k=0;
   while(T--)
   {
       cin>>n>>k;
       int num=2*n;
       vector<int> card(num);//先把空间开好
       for(int i=0;i<num;i++)//插入牌
       {
           cin>>card[i];
       }
      
       for(int i=0;i<k;i++)
       { 
           vector<int> tmp(card.begin(),card.end());//拷贝构造
           for(int j=0;j<n;j++)//只遍历到n，因为分为左右牌
           {
               card[2*j] = tmp[j]; //左手的牌排放的位置 
               card[2*j+1] = tmp[j+n];//右手的牌排放的位置
           }
       }

        //输出洗牌的顺序
         for(int i=0; i<num-1; ++i) 
        {
         cout<<card[i]<<" "; 
        } 
        cout<<card[num-1]<<endl; //最后一张牌后面不能有空格
         
   }
   return 0;
}

