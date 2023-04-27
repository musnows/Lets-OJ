class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0,right = numbers.size()-1;
        while(left<right)
        {
            int sum = numbers[left]+numbers[right];
            if(sum>target)
            {
                right--;//数字大了，右侧--
            }
            else if(sum<target)
            {
                left++;//数字小了，左侧++
            }
            else
            {//找到了
                return {left,right};
            }
        }
        return {left,right};
    }
};

//https://leetcode.cn/problems/kLl5u1/description/
