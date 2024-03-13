class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 使用前后指针方法
        int slow = 0;
        int count = 0;
        for(int fast = 0;fast<nums.size();fast++)
        {
            // 如果当前位置等于value，则只走fast指针
            if(nums[fast] == val){
                count++; // 计算有多少个value值
                continue;
            }
            else
            {   
                // 不等于value，二者都走一步并赋值
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return nums.size()-count; // 覆盖后的数组
    }
};

// https://leetcode.cn/problems/remove-element/description/
// 在数组中原地删除值为value的元素，不需要管新数组长度之后的数组中元素

// 当f走到2的时候，只走f，其他情况都会进行a[slow]=a[fast]的赋值操作
// 0,1,2,2,3,0,4,2   val = 2
// s
// f
// 在f没有遇到val之前，它和slow指针的位置是一样的
// 0,1,2,2,3,0,4,2   val = 2
//     s
//     f
// f遇到了value，slow指针不会动，直到fast走到下一个不为value的位置，继续开始覆盖
// 0,1,2,2,3,0,4,2   val = 2
//     s
//         f
// 0,1,3,2,3,0,4,2   val = 2
//       s
//           f
// 0,1,3,0,3,0,4,2   val = 2
//         s
//             f
// 0,1,3,0,4,0,4,2   val = 2
//           s
//               f
// f又走到了value的位置（最后一个2），此时count为3，下一步f就越界了
// 0,1,3,0,4,0,4,2   val = 2
//           s
//                 f
// 此时已经得到了需要返回的数组 0,1,3,0,4
// 这个数组的长度是原有数组的长度-count，即8-3=5
// 返回长度5即可
