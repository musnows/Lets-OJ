// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

// 示例 1:

// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 1;
        while(fast < nums.size())
        {
            if(nums[slow] == 0)
            {
                while(fast < nums.size() && nums[fast] == 0)
                {
                    fast ++;
                }
                // 第一个不为0的
                if(fast < nums.size()){
                    nums[slow] = nums[fast];
                    nums[fast] = 0;
                }
                else{
                    break;
                }
            }
            slow ++;
            fast ++;
        }

    }
};