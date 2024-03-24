class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            // 在右边
            if (nums[mid] == nums[mid ^ 1]) {
                left = mid + 1;
            } else // 在左边
            {
                right = mid;
            }
        }
        return nums[left];
    }
};
// https://leetcode.cn/problems/single-element-in-a-sorted-array/description/