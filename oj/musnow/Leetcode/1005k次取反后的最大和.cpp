class Solution {
    // 按绝对值从大到小排序
    static bool cmp(int a, int b) { return abs(a) > abs(b); }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 绝对值从大到小排列
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            // 反转负数
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        // 如果k还没有用完，则反转绝对值最小的那个数，直到用完k
        // 这里直接判断k是奇数还是偶数，如果是奇数会多出来一次反转，只需要做这一次就可以了
        if (k % 2 == 1) {
            nums[nums.size() - 1] *= -1;
        }
        // 求和
        int sum = 0;
        for (auto& e : nums) {
            sum += e;
        }
        return sum;
    }
};