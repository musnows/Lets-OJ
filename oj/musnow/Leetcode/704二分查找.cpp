class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size();
        // 开区间,right不在下标中
        while(left < right)
        {
            int mid = (left + right )/2;
            if(nums[mid] < target)
            {
                left = mid+1;
            }
            else if(nums[mid] > target)
            {
                right = mid; // 开区间，right不需要修正
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        // 闭区间，right在下标中
        while(left <= right)
        {
            int mid = (left + right )/2;
            if(nums[mid] < target)
            {
                left = mid+1;
            }
            else if(nums[mid] > target)
            {
                right = mid-1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
// 两种方式都测试通过了
// https://leetcode.cn/problems/binary-search/