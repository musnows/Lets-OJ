class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            // 只有一个元素，本来就是从这里起跳的，肯定可以达到
            return true; 
        }
        int cover = 0;
        // 注意这里是小于等于cover，cover是闭区间
        for (int i = 0; i <= cover; i++) { 
            // 判断当前能跳的范围和cover谁大
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) {
                return true; // 说明可以覆盖到终点了
            }
        }
        return false;
    }
};