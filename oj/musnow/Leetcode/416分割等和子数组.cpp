class Solution {
    // 01背包问题，判断背包能不能做到装sum/2的数据
    // 能做到就说明有解（回溯法会超时）
    bool _canPartition(vector<int>& nums, int target) {
        // 背包问题中，行代表物品，列代表背包容量
        // 本题背包容量是target，行是每一个数字
        vector<int> mtx(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            // nums[i]之前是放不下这个数字的，跳过
            // 从后往前，避免每一轮的结果影响后面的操作
            for (int j = target; j >= nums[i]; j--) {
                mtx[j] = max(mtx[j], mtx[j - nums[i]] + nums[i]);
            }
        }
        return mtx[target] == target;
    }

public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (auto& i : nums) {
            sum += i;
        }
        int target = sum / 2;
        if (sum % 2 != 0) {
            return false;
        }
        return _canPartition(nums, target);
    }
};