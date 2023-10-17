//https://leetcode.cn/problems/kLl5u1/solutions/1398898/pai-xu-shu-zu-zhong-liang-ge-shu-zi-zhi-8tv13/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low, high};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};

