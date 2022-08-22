//35. 搜索插入位置
//https://leetcode.cn/problems/search-insert-position/
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 请必须使用时间复杂度为 O(log n) 的算法。
int searchInsert_1(int* nums, int numsSize, int target){
    int i=0;
    for(i=0;i<numsSize;i++)//o(N)的算法不符合题目要求
    {
        if(nums[i]==target)
        {
            return i;
        }
        else if(nums[i]>target){
            return i;
        }
    }
    return numsSize;
}
// 执行用时：4 ms, 在所有 C 提交中击败了93.15%的用户
// 内存消耗：6 MB, 在所有 C 提交中击败了22.47%的用户


//二分查找
int searchInsert_2(int* nums, int numsSize, int target){
    if(target>nums[numsSize-1]){
        return numsSize;//单独处理最大的情况
    }
    int begin = 0;
    int end = numsSize-1;
    int mid = begin + ((end-begin)>>1);
    while (begin < end)
    {
        mid = begin + ((end-begin)>>1);
        //使用位移操作符来模拟/2，防止begin和end相加后超出int范围
        if (nums[mid] < target)
            begin = mid+1;
        else if (nums[mid] > target)
            end = mid;
        else
            return mid;
    }
    //mid是离target很近的一个数据，因为target不总是在数组中
    //所以我们需要判断mid和target的大小差距
    if(nums[mid]>=target){
        return mid;
    }
    return mid+1;
}
// 执行用时：4 ms, 在所有 C 提交中击败了93.15%的用户
// 内存消耗：5.9 MB, 在所有 C 提交中击败了44.55%的用户
