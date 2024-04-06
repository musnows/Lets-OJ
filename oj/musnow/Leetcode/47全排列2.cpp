class Solution {
    vector<vector<int>> retV;
    vector<int> curV;
    vector<bool> used;
    // 同样每一次都是从0开始，但是需要跳过单层已经被选择过的元素
    void _permuteUnique(vector<int>& nums) {
        // 长度相等代表找到了一个全排列
        if (curV.size() == nums.size()) {
            retV.push_back(curV);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 跳过相同的（前提是同层上一位已经被选择过了）
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            // 正常情况下也需要跳过被选用了的
            if (used[i] == true) {
                continue;
            }
            curV.push_back(nums[i]);
            used[i] = true;

            _permuteUnique(nums);

            used[i] = false;
            curV.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());

        _permuteUnique(nums);
        return retV;
    }
};