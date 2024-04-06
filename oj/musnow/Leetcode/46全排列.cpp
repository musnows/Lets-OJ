class Solution {
    vector<vector<int>> retV;
    vector<int> curV;
    vector<bool> used;
    // 因为全排列每次都需要从0开始，所以不需要startIndex
    void _permute(vector<int>& nums) {
        // 长度相等代表找到了一个全排列
        if (curV.size() == nums.size()) {
            retV.push_back(curV);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {
                continue; // 跳过已经被选择了的
            }
            curV.push_back(nums[i]);
            used[i] = true;

            _permute(nums);

            used[i] = false;
            curV.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false); // 注意初始化
        _permute(nums);
        return retV;
    }
};