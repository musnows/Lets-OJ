class Solution {
public:
    bool isDouble(int a)
    {
        if(a%2==0)
        {
            return true;
        }
        return false;
    }
    vector<int> sortArrayByParityII(vector<int>& nums) {
        //原 4 2 5 7
        //目 4 5 2 7
        stack<int> _vDouble;
        stack<int> _vSingle;
        for(int i=0;i<nums.size();i++)
        {
            if(isDouble(nums[i]))
            {// 偶数
               _vDouble.push(nums[i]); 
            }
            else
            {// 奇数
                _vSingle.push(nums[i]);
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            int tmp;
            if(isDouble(i))
            {
                tmp = _vDouble.top();
                _vDouble.pop();
            }
            else
            {
                tmp = _vSingle.top();
                _vSingle.pop();
            }
            nums[i] = tmp;
        }
        return nums;
    }
};
//题目要求下标偶数，元素也需要是偶数（奇偶对应）
//https://leetcode.cn/problems/sort-array-by-parity-ii/description/

//双指针写法

class Solution {
public:
    bool isDouble(int a)
    {
        return (a%2==0);
    }
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int fast=1;//fast维护奇数
        for(int i=0;i<nums.size();i+=2)
        {
            if(!isDouble(nums[i]))
            {//如果不是偶数，继续循环
                while(!isDouble(nums[fast]))
                {
                    fast+=2;
                }
                //是偶数
                swap(nums[i],nums[fast]);//交换
            }
        }
        return nums;
    }
};