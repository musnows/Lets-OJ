// 15. 三数之和  https://leetcode.cn/problems/3sum/
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
//
//你返回所有和为 0 且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。

//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//注意，输出的顺序和三元组的顺序并不重要。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> result;
       sort(nums.begin(), nums.end());

       for(int i = 0; i<nums.size(); i++)
       {
            if(nums[i]>0)
                return result;

            if(i>0 && nums[i] == nums[i-1])
                continue;

            int left = i+1;
            int right = nums.size()-1;
            while(left<right)
            {
                if(nums[i]+nums[left]+nums[right]>0) right--;
                else if(nums[i]+nums[left]+nums[right]<0) left++;
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while(left<right && nums[left] == nums[left+1]) left++;
                    while(left<right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                }
            }
       }
       return result;
    }
};
