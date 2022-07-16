//https://leetcode.cn/problems/single-number-iii/submissions/
//这道题和https://blog.csdn.net/muxuen/article/details/123313712是一样的，我之前写过笔记
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //1.全部异或在一起
        int numsSize=nums.size();
        int i = 0;
        int k = 0;
        for (i = 0; i < numsSize; i++)
        {
            k ^= nums[i];
            //4^1^4^6 = 1^6
        }
        //2.判断k的二进制第几位是1
        int set = 0;
        for (i = 0; i < 32; i++)
        {
            if (((k >> i) & 1) == 1)//注意操作符优先级
            {
                set = i;//第i位为1
                break;
            }
        }
        //3.以第set位为1进行分组，可以将这两个数分开
        int n = 0;
        int m = 0;
        for (i = 0; i < numsSize; i++)
        {
            if (((nums[i] >> set) & 1) == 1)
            {
                n ^= nums[i];
            }
            else
            {
                m ^= nums[i];
            }
        }
        
        vector<int> retV;
        retV.push_back(n);
        retV.push_back(m);
        return retV;
    }
};