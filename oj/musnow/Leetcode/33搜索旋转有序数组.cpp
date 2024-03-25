class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 旋转后的数组肯定是一部分有序的
        // 这个有序的部分肯定是在mid左侧或者右侧！
        // 题目中的旋转是从k开始（包括k）往后的数字移动到数组的开头
        // 不管k选择哪里都肯定符合上面的这个条件，永远会有一边的数字更多
        // [4,5,6,7,0,1,2] 以mid=3分割
        // [4,5,6,7]       有序
        //       [7,0,1,2] 无序

        int left = 0, right = nums.size() - 1;
        // 如果要使用小于等于，那么left和right应该都是闭区间
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 中间能找到
            if (nums[mid] == target) {
                return mid;
            }
            // 找不到，判断左侧或者右侧是否有序
            if (nums[left] <= nums[mid]) // 左侧有序
            {
                // 判断值是否在左侧
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else // 左侧虽然有序，但是值在右侧
                {
                    left = mid + 1;
                }
                continue;
            }
            // 左半部分不是有序，说明右半部分是有序的
            else {
                // 值在右侧
                if (nums[right] >= target && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                continue;
            }
        }
        return -1;
    }
};