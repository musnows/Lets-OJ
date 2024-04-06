class Solution {
    vector<vector<int>> retV;
    vector<int> curV;
    void _findSubsequences(vector<int>& nums, int startIndex) {
        // 题目要求子序列必须有两个元素
        if (curV.size() > 1) {
            retV.push_back(curV);
        }
        // 越界终止
        if (startIndex >= nums.size()) {
            return;
        }
        // 单层for中不能选择已经选过的数
        // unordered_set<int> used; // 去重集合
        // 因为题目给出了数字的区间是-100到100，可以直接用一个201长度的数组做哈希，提高效率
        vector<bool> usedArray(201, false); // num[i] + 100 作为下标
        // 单层for
        for (int i = startIndex; i < nums.size(); i++) {
            // 因为在for中每次都只会往curV插入一个数，所以可以直接判断
            // 如果当前位小于startIndex-1，跳过
            if (startIndex - 1 >= 0 && i > startIndex - 1 &&
                nums[i] < nums[startIndex - 1]) {
                continue;
            }
            // 单层for中不能选择已经选过的数
            // if (used.count(nums[i]) != 0)
            if (usedArray[nums[i] + 100] != false) {
                continue;
            }
            // 插入本层
            // used.insert(nums[i]);
            usedArray[nums[i] + 100] = true; // 标记已经使用过了
            curV.push_back(nums[i]);
            // 递归下一层
            _findSubsequences(nums, i + 1);
            // 回溯
            curV.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        _findSubsequences(nums, 0);
        return retV;
    }
};