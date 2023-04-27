class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());//排序
        int i=0,j=0,left=0,right=0;
        long long sum;
        for(i=0;i<nums.size();i++)
        {
            // 因为target是变的，所以不能单纯的用三数之和的思路来判断（那道题target为0）
            // 比如target=-11，数组中第一个值是-6，但是还有其他负数加起来可能是-11
            // 所以判断的时候，如果nums[i]大于0还大于target，就代表没办法获得到target了
            if(nums[i]>target && nums[i]>=0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            //降维后的target
            for(j=i+1;j<nums.size();j++)
            {
                // 如果相加大于0，跳过这次循环
                if(nums[i]+nums[j]>target && nums[i]+nums[j]>=0){
                    break;
                }
                //要从起始开始判断前一位，j的开始是i+1
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                left=j+1;
                right=nums.size()-1;//最后一个元素
                while(left<right)
                {   
                    // 这里用int会溢出，得强转
                    // sum = nums[i]+nums[j]+nums[left]+nums[right];
                    sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];
                    //io导致超时！！！！！
                    //printf("sum: %d %d %d %d = %d\n",nums[i],nums[j],nums[left],nums[right],sum);
                    if(sum>target)//大于零缩小右边界
                        right--;
                    else if(sum<target)//小于0缩小左边界
                        left++;
                    else{
                        //printf("insert:%d %d %d %d\n",nums[i],nums[j],nums[left],nums[right]);
                        ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                        // 这里和i的情况不同，有一个数字已经固定了，所以可以继续缩小找其他的
                        while(left<right && nums[right]==nums[right-1])
                            right--;
                        while(left<right && nums[left]==nums[left+1])
                            left++;
                        // 再缩小一次
                        left++;
                        right--;
                    }
                }
            }
        }

        return ret;
    }
};
//https://leetcode.cn/problems/4sum/

//找了好久的问题，最后发现是那两个printf导致的超时，哭了