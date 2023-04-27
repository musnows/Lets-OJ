//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
//26. 删除有序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //双指针遍历
    int pre=0;
    int next=1;//如果相等，next后移一位
    while(next<nums.size())//如果不相等，next复制到pre+1的位置，next，pre后移一位
    {
       if(nums[pre]!=nums[next])
       {   
           if(next-pre>1)
           nums[pre+1]=nums[next];
           pre++;
       }
       next++;
    }
    return pre+1;
    }
};
