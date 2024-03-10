// https://leetcode.cn/problems/move-zeroes/description/?envType=study-plan-v2&envId=top-100-liked
// 将数组的0全部移动到末尾，且不影响其他元素的相对位置
// 使用双指针法遍历
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = slow +1;
        while(fast < nums.size())
        {
            // 如果slow为0，则让fast去找下一个不为0的数字
            if(nums[slow] == 0)
            {
                // 找到第一个不为0的数字
                while(fast <  nums.size() && nums[fast] == 0){
                    fast++;
                }
                // 这里必须要判断fast是否走过头了
                if(fast <  nums.size()){
                    nums[slow] = nums[fast]; // 覆盖前面的
                    nums[fast] = 0;
                }
                else{
                    break;
                }
            }
            // 不管什么情况slow和fast都加加
            slow++;
            // 假设有覆盖，那么当前fast的位置是0，它需要从下一位开始找。
            // 假设没有覆盖，只加slow会让fast可能落后于slow，不合题意
            fast++;
        }
    }
};