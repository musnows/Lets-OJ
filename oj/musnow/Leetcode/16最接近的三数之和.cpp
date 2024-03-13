class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int retNum = INT_MAX; // 差距值
        int retSum = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
        {
            // 先匹配再去重
            if(i>0 && nums[i] == nums[i-1]){
                continue; 
            }

            int left = i+1,right = nums.size()-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target){
                    return target;
                }
                // 更新结果值
                int diff = abs(target-sum);
                if(diff < retNum)
                {
                    retNum = diff;
                    retSum = sum;
                }

                if(sum >= target){
                    while(left<right && nums[right] == nums[right-1]){
                        right--;
                    }
                    // 必须要再操作一次才是下一个
                    right--;
                }
                else if(sum < target){
                    while(left<right && nums[left] == nums[left+1]){
                        left++;
                    }
                    // 必须要再操作一次才是下一个
                    left++;
                }
            }
        }
        return retSum;
    }
};