class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        // 因为题目没有要求不能是同一个数组
        // 也没有要求4个数必须不同
        unordered_map<int,int> m1;//用于计算数组1和2中数字之和的个数
        for(auto&e:nums1)
        {
            for(auto&v:nums2)
            {
                m1[e+v]++;
            }
        }
        //再在3和4中计算两数相加的和K，判断if(0-K in m1)
        //如果在代表有相加为0的4个数，该组合的元组个数即为m1中记录的value
        //count加上value就可以了
        for(auto&e:nums3)
        {
            for(auto&v:nums4)
            {
                int ret = e+v;
                ret = 0-ret;//计算差值
                // m1中有这个差值
                if(m1.find(ret) != m1.end())
                {  
                    count+=m1[ret];
                }
            }
        }
        return count;
    }
};
//https://leetcode.cn/problems/4sum-ii/