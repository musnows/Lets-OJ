//https://leetcode.cn/problems/search-in-rotated-sorted-array/
//33. 搜索旋转排序数组
//1暴力
int search1(int* nums, int numsSize, int target){
    int i=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==target)
        {
            return i;
        }
    }
    return -1;
}


//2二分
//a 数组，n长度，x需要查找的数
int BinarySearch(int* a,int begin, int end, int x)
{
    assert(a);
    // int begin = 0;
    // int end = n-1;
    while (begin <= end)
    {
        int mid = begin + ((end-begin)>>1);//使用位移操作符来模拟/2，防止begin和end相加后超出int范围
        if (a[mid] < x)
            begin = mid+1;
        else if (a[mid] > x)
            end = mid-1;
        else
            return mid;//返回需要查找的数的下标
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    int i=1;
    while(i<numsSize && nums[i]>nums[i-1])
    {
        if(nums[i]==target){
            return i;//找定位点的途中顺便找找target
        }
        i++;
    }
    int ret1 = BinarySearch(nums,0,i-1,target);
    int ret2 = BinarySearch(nums,i,numsSize-1,target);
    //printf("%d %d",ret1,ret2);
    return ret1>ret2?ret1:ret2;//如果ret1更大，说明re1找到了
    //如果不存在，则会返回ret2(也是-1)
}
