class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        // 当前的跳跃范围
        int curJump = 0;
        int maxJump = 0; // 判断范围内可以跳的最大值
        int count = 0;   // 跳了几次
        for (int i = 0; i < nums.size(); i++) {
            // 更新在[i,curJump]范围内下一步可以跳的最大范围
            maxJump = max(i + nums[i], maxJump);
            // 到达右边界了，必须再跳一步了。
            if (i == curJump) {
                count++;
                curJump = maxJump;
                // 可以跳到下一步（这里提前count++就相当于跳了这一步）
                if (maxJump >= nums.size() - 1) {
                    return count;
                }
            }
        }
        return count;
    }
};