class Solution {
    void _combinationSum(vector<int>& candidates, int target, int sum,
                         int starti, vector<int> curV,
                         vector<vector<int>>& retV) {
        // 值相等，插入
        if (sum == target) {
            retV.push_back(curV);
            return;
        }
        // 值已经大于了，不进入
        if (sum > target) {
            return;
        }
        // 每一层都是直接重新遍历整个数组
        for (int i = starti; i < candidates.size(); i++) {
            // 值已经大于了，不进入
            if (sum + candidates[i] > target) {
                continue; // 数组不一定是升序排列的，所以还需要往后走
            }
            curV.push_back(candidates[i]);
            _combinationSum(candidates, target, sum + candidates[i], i, curV,
                            retV);
            curV.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> retV;
        if (candidates.size() == 0) {
            return retV;
        }
        _combinationSum(candidates, target, 0, 0, vector<int>(), retV);
        return retV;
    }
};

// https://leetcode.cn/problems/combination-sum/description/