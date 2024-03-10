class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //这里使用set也是可以的，但是set会对数据进行排序，而我们只是需要一个能够去重的数据结构
        //所以基于哈希的unordered set是更好的选择
        unordered_set<int> ret;//返回值的哈希（因为键值不能冗余）
        unordered_set<int> nums;//记录nums1的哈希
        for(auto&e:nums1)
        {
            nums.insert(e);
        }
        for(auto&e:nums2)
        {
            //在1里面找到了
            if(nums.find(e)!=nums.end())
            {
                ret.insert(e);
            }
        }
        return vector<int>(ret.begin(),ret.end());
    }   
};
//https://leetcode.cn/problems/intersection-of-two-arrays/submissions/