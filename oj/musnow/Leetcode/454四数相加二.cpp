class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> maps;
        for(auto &e1:nums1)
        {
            for(auto&e2:nums2){
                maps[e1+e2]++;
            }
        }
        int count = 0;
        for(auto &e3:nums3)
        {
            for(auto&e4:nums4){
                auto ret =maps.find(0-(e3+e4));
                if(ret != maps.end()){
                    count += ret->second;
                }
            }
        }
        return count;
    }
};
// https://leetcode.cn/problems/4sum-ii/description/
// 先算前两个数组的元素和，再在后两个数组中找有没有符合条件的