class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 用双指针法实现
        vector<vector<int>> retV;
        sort(nums.begin(),nums.end()); // 先排序
        for(int i=0;i<nums.size();i++)
        {
            // 第一个元素都大于0了，肯定不会有和为0的结果，直接退出
            if(nums[i] > 0) // 这里不能是>=，因为可能会有0 0 0这个三元组的情况
            {
                break;
            }
            // 首先要对i去重，然后是对left和right指向的元素去重
            // if(nums[i] == nums[i+1]) // 这种方式不正确，会错过 -1 -1 2 的情况
            // 去重的核心思想应该是先匹配上再跳过，而不是先跳过相同元素再匹配

            // 对i的结果去重
            if(i>0 && nums[i] == nums[i-1])
            {
                // i++; // 错误操作，for中的i位置变动了，最终会多++一次导致漏掉东西
                continue;
            }

            int left = i+1,right = nums.size()-1;
            while(left<right)
            {
                int sum = nums[i] + nums[right] + nums[left];
                if(sum > 0)
                {
                    right--;
                }
                else if(sum <0)
                {
                    left++;
                }
                else
                {
                    retV.push_back(vector<int>{nums[i],nums[right], nums[left]});
                    // 接下来要去掉相同的值，直接走到下一个不相同的值的位置
                    // -3 -1 -1 0 3 3 4
                    // i   l          r
                    // 此时匹配上了，l应该走到0的位置进行下一次匹配，r应该走到3的位置进行匹配
                    while(left < right && nums[left+1] == nums[left])
                    {
                        left++;
                    }
                    while(left < right && nums[right-1] == nums[right])
                    {
                        right--;
                    }
                    // 当这两个while循环结束的时候，l和r的位置还不是下一个目标位置
                    // -3 -1 -1 0 3 3 4
                    // i      l       r
                    // 这里还需要再走一步才是和刚刚不相同的值
                    left++;
                    right--;
                    // -3 -1 -1 0 3 3 4
                    // i        l   r
                }
            }
        }
        return retV;
    }
};
// https://leetcode.cn/problems/3sum/description/
// 选出数组中相加为0的三元组，不能重复