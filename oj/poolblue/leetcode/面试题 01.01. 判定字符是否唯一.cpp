//https://leetcode.cn/problems/is-unique-lcci/
//面试题 01.01. 判定字符是否唯一
class Solution {	
public:
    bool isUnique(string astr) {
       int count [26]={0};
     //统计次数
     for( auto ch :astr)
     {
         count[ch-'a']++;
     }

     for(size_t i=0;i<astr.size();i++)
     {
         if(count[astr[i]-'a']>1)
          return false;
         
     }
     return true;

    }
};
