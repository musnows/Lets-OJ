//137. 只出现一次的数字 II
//https://leetcode.cn/problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //排序之后，相同的3个数肯定在一起
        vector<int>::iterator it1=nums.begin();
        vector<int>::iterator it2=nums.begin()+1;
        while(it2!=nums.end())
        {
            if(*it2 != * it1)
            {
                return *it1;
            }
            //以3为单位进行比较，相邻两个不同表示有一个是单身狗
            it1+=3;
            it2+=3;
        }
        //避免it2走完了it1还没走完的情况
        //这时候*it1就是结果
        return *it1;
    }
};