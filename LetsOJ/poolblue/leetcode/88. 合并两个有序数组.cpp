//https://leetcode.cn/problems/merge-sorted-array/
    class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=nums1.size()-1;//下标为nums1最后一个元素
        //记住下标
        m--;
        n--;
        while(n>=0)//从nums1最后开始放入元素，分别从俩个数组最后的元素进行比较
        {   
            while(m>=0 && nums1[m]>nums2[n])//若第一个数组最后的元素大于第二个数组最后的元素
            {
                swap(nums1[i--],nums1[m--]);//为最大元素，交换，放入数组最后，并递减
            }
            swap(nums1[i--],nums2[n--]);//反之，放入第二个数组最后的元素，并递减
        }

        }
    };
