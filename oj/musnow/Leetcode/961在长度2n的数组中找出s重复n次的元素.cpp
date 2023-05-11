ass Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int> temp(nums);
        // 1.排序
        sort(temp.begin(),temp.end());

        // 2.直接获取sz/2
        int sz = temp.size();
        // 3.需要判断重复n次的元素是在sz/2的左边还是他自己
        //   sz和sz+1相同，说明是它自己
        if(temp[sz/2]==temp[sz/2+1])
        {
            return temp[sz/2];
        }
        else
        {   
            //其他情况说明是sz-1
            return temp[sz/2-1];
        }
        
        return temp[sz/2];
    }
};

//961. 在长度 2N 的数组中找出重复 N 次的元素
//https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/
