class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 在三数之和的基础上多套一层循环
        vector<vector<int>> retV;
        sort(nums.begin(),nums.end());
        for(int j = 0;j<nums.size();j++)
        {
            // 这里不需要判断是否大于target，因为target可能是负数
            // 大于target的负数相加也有可能等于target
            
            // j去重
            if(j>0 && nums[j] == nums[j-1])
            {
                continue;
            }
            for(int i = j+1;i<nums.size();i++)
            {
                // i去重
                if(i> j+1 && nums[i] == nums[i-1])
                {
                    continue;
                }
                long long fixSum = nums[j] + nums[i];
                int left = i +1,right = nums.size()-1;
                while(left < right)
                {
                    // 直接四数相加会越界
                    // long long sum = nums[j] + nums[i] + nums[left] + nums[right];
                    long long lrSum = nums[left] + nums[right]; 
                    if(fixSum > (long long)target - lrSum)// 需要改long long否则也会越界
                    {
                        right--;
                    }
                    else if(fixSum < (long long)target - lrSum)
                    {
                        left++;
                    }
                    else
                    {
                        retV.push_back(vector<int>{nums[j] , nums[i] , nums[left] ,nums[right]});
                        while(left<right && nums[right] == nums[right-1]){
                            right--;
                        }
                        while(left<right && nums[left] == nums[left+1]){
                            left++;
                        }
                        // 还需要再收缩一次才是目标值
                        right--;
                        left++;
                    }
                }
            }
        }
        return retV;
    }
};
// https://leetcode.cn/problems/4sum/
// 在15题三数相加基础上多加一个循环就行
// 注意不能直接相加四个数字，否则会越界