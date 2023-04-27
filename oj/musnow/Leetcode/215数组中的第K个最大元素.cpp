//215. 数组中的第K个最大元素
//https://leetcode.cn/problems/kth-largest-element-in-an-array/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //优先级队列默认是大堆，数据从大到小存放
        priority_queue<int> q1;
        for(auto ch:nums){
            q1.push(ch);
        }
        //我们只需要pop掉前面的k-1个元素
        while(!q1.empty()&&k>1){
            q1.pop();
            k--;
        }
        //此时top就是我们需要的第k个最大值
        return q1.top();
    }
};