/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int* arr=(int*)malloc(sizeof(int)*numsSize);
    int i=0;
    arr[0]=nums[0];
    printf("%d",numsSize);
    for(i=1;i<numsSize;i++)
    {
        arr[i]=arr[i-1]+nums[i];
    }
    
    *returnSize=numsSize;
    return arr;
}

//1480. 一维数组的动态和
//https://leetcode.cn/problems/running-sum-of-1d-array/
// 输入：nums = [1,2,3,4]
// 输出：[1,3,6,10]
// 解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
