class Solution {
    void _combinationSum2(vector<int>& candidates, int target, int sum,
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
            // 当前值和上一次相同，跳过
            if(i > starti && candidates[i] == candidates[i-1]){
                continue;
            }
            // 值已经大于了，不进入
            if (sum + candidates[i] > target) {
                continue; // 数组不一定是升序排列的，所以还需要往后走
            }
            curV.push_back(candidates[i]);
            // 这道题就需要对i加一了，因为不能选择相同的数字
            _combinationSum2(candidates, target, sum + candidates[i], i + 1,
                             curV, retV);
            curV.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> retV;
        if (candidates.size() == 0) {
            return retV;
        }
        sort(candidates.begin(),candidates.end());
        _combinationSum2(candidates, target, 0, 0, vector<int>(), retV);
        return retV;
    }
};