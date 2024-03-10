
te: The returned array must be malloced, assume caller calls free().
 */
void swap(int* a,int* b)
{
    int tmp = *a;
    (*a)=(*b);
    (*b)=tmp;
}
int cmp(const void* e1,const void* e2)
{
    return *(int*)e1>*(int*)e2;
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int m = 0;//标记位
    for(int i =0;i<arr2Size;i++)
    {
        for(int j = 0 ;j <arr1Size;j++)
        {
            if(arr1[j]==arr2[i])
            {
                swap(&arr1[j],&arr1[m]);
                m++;
            }
        }
    }
    //printf("%d %d",m,arr1Size-1-m);
    //后面的部分需要排序
    qsort(arr1+m,arr1Size-m,sizeof(int),cmp);

    *returnSize=arr1Size;
    return arr1;
}
//1122. 数组的相对排序
//https://leetcode.cn/problems/relative-sort-array/
