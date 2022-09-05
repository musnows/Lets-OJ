#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#include<stdbool.h>
#include<math.h>

// int findLHS(int* nums, int numsSize){
//     if(numsSize==1){
//         return 0;
//     }
//     int max=0;//最长的序列
//     int* arr=(int*)malloc(sizeof(int)*(numsSize+1));
//     for(int i =0;i<numsSize;i++)
//     {
//         int sum=0;//单次长度
//         int comp=nums[i];//比较值
//         int flag = 0,set;//标志
//         int m=0;
//         for(int j =0;j<numsSize;j++)
//         {
//             if(nums[j]==comp){
//                 arr[m++]=nums[j];
//                 sum++;
//             }
//             else if((fabs(nums[j]-comp))==1){
//                 if(flag==0){
//                     set = nums[j];//第一次进入先赋值
//                     flag=1;//后续不修改set
//                 }
//                 if(set==nums[j]){
//                     arr[m++]=nums[j];
//                     sum++;
//                 }
//             }
//         }

//         for(int n=0;n<m;n++){
//             printf("%d ",arr[n]);
//         }
//         if(sum>max && flag!=0){
//             max=sum;
//         }

//     }


//     return max;
// }


int cmp(int *a,int *b){
    return *a-*b;
}
int findLHS(int* nums, int numsSize){
    int len=numsSize;
    if(len==1)
        return 0;
    qsort(nums,len,sizeof(int),cmp);
    int max=0;
    for(int j=0,i=0;i<len;i++){
        while(j<i&&nums[i]-nums[j]>1)
        {
            j++;
        }
        if(nums[i]-nums[j]==1){
            max=fmax(max,i-j+1);
        }
    }
    return max;
}


//https://leetcode.cn/problems/longest-harmonious-subsequence/
int main()
{
    int arr[] = {0,7,9,9,3,5,4,3,2,3,3,9,0,4,5,1,0,10,5,5,4,9,-5,2,6,5,9,5,1,6,6,7,9,5,2,1,0,7,2,9,7,4,7,9,3,6,9,2,10,9,1,7,8,8,8,7,4,2,7,9,-4,3,0,6,3,8,3,0,9,4,6,10,1,6,10,0,2,3,2,7,9,8};
    int sz = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,sz,sizeof(int),cmp);
    // for(int i=0;i<sz;i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    int res = findLHS(arr,sz);
    printf("%d\n",res);
    return 0;
}
