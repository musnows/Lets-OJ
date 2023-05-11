class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;//哈希表 数据-下标
        vector<int> ret;//返回值
        for(int i=0;i<nums.size();i++)
        {
	        //找有没有和（目标-当前值）相同的元素
            auto it = m.find(target-nums[i]);
            if(it!=m.end())//找到了
            {
                ret.push_back(it->second);//插入哈希表中下标
                ret.push_back(i);//插入当前下标
                break;//退出循环
            }
            else
            {
                m.insert({nums[i],i});//插入元素和下标
            }
        }
        return ret;
    }   
};
//https://leetcode.cn/problems/two-sum/