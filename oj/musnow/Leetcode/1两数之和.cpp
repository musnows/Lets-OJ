class Solution {
public:
    // 思路简单，使用哈希判断数组中是否存在target-当前值的结果，如果存在则符合题意，进行返回
    // 哈希map的时间复杂度是O(1)，所以整个算法的时间复杂度O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> maps;
        vector<int> retV;
        for(int i =0;i<nums.size();i++){
            // 找到了代表存在
            auto ret = maps.find(target - nums[i]);
            if(ret != maps.end())
            {
                retV.push_back(i);
                retV.push_back(ret->second);
                return retV;
            }
            // 没有找到则插入
            maps.emplace(nums[i],i);
        }
        return retV;
    }
};