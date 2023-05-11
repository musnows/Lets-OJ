//18. 四数之和 https://leetcode.cn/problems/4sum/
//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
//
//0 <= a, b, c, d < n
//a、b、c 和 d 互不相同
//nums[a] + nums[b] + nums[c] + nums[d] == target
//你可以按 任意顺序 返回答案 。

//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int k = 0; k<nums.size(); k++)
        {
            if(nums[k]>=0 && nums[k]>target)// a剪枝
                break;

            if(k>0 && nums[k] == nums[k-1]) continue;

            for(int i = k+1; i<nums.size(); i++)
            {
                if(nums[i]+nums[k]>=0 && nums[i]+nums[k]>target)// b剪枝
                break;

                if(i>k+1 && nums[i] == nums[i-1]) continue;

                int left = i+1;
                int right = nums.size()-1;
                while(left<right)
                {
                    // 会溢出
                    if((long)nums[k]+nums[i]+nums[left]+nums[right]>target) right--;
                    else if((long)nums[k]+nums[i]+nums[left]+nums[right]<target) left++;
                    else
                    {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // c,d剪枝
                        while(left<right && nums[left] == nums[left+1]) left++;
                        while(left<right && nums[right] == nums[right-1]) right--;

                        left++;
                        right--;
                    }

                }
            }
        }
        return result;

    }
};
