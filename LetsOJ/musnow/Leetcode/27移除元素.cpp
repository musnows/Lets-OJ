class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 用快慢指针的思路
        int slow=0,fast=0;
        for(fast = 0;fast<nums.size();fast++)
        {
            // 如果快指针遍历到的元素不为目标元素
            if(nums[fast]!=val)
            {
                nums[slow++]=nums[fast];//正常情况下，这两个本身就是相等的
            }
            // 如果是，这时候只有快指针++
            // 慢指针原地不动，从下一位开始，就会变成将后一位往前覆盖
        }
        return slow;//慢指针最后停下的位置就是新数组长度
    }
};
//https://leetcode.cn/problems/remove-element/submissions/