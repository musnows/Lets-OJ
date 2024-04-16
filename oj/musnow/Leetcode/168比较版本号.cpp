class Solution {
public:
    int compareVersion(string version1, string version2) {
        int left = 0, right = 0;
        while (left < version1.size() || right < version2.size()) {
            // version1求和
            int leftSum = 0;
            // 这里并不需要对前导0做任何判断，因为初始值就是0，前导0操作后还是0
            for (; left < version1.size() && version1[left] != '.'; left++) {
                leftSum = leftSum * 10 + (version1[left] - '0');
            }
            left++; // 跳过点

            // version2求和
            int rightSum = 0;
            for (; right < version2.size() && version2[right] != '.'; right++) {
                rightSum = rightSum * 10 + (version2[right] - '0');
            }
            right++; // 跳过点

            // 不相同就说明有一个大了，判断一下
            if (leftSum != rightSum) {
                return leftSum > rightSum ? 1 : -1;
            }
        }
        return 0;
    }
};