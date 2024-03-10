class Solution {
public:
    // 使用第一个数组构建一个set
    // 第二个数组在这个set里面找，存在则插入到结果集中
    // 先用一个set存放结果集，这样能避免判断是否已经插入
    // 最终再将结果集set转回题目需要的vector并返回

    // redis中的set也可以用来求交集和并集，本质上和这里的思路是一致的。
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> sets(nums1.begin(),nums1.end());
        unordered_set<int> retSet;
        for(auto&e:nums2)
        {
            if(sets.count(e)){
                retSet.insert(e);
            }
        }
        vector<int> retV(retSet.begin(),retSet.end());
        return retV;
    }
};