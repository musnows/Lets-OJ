https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

     //如果长度小于等于1，不用排序
	if (nums.size() <= 1) return 0;
	int len=nums.size(),low = 0, high = len - 1, maxNum = nums[0], minNum = nums[len - 1];
	//从左向右，保存该过程中的最大值，当当前值与MAX进行对比，如果小于的话说明已经到达了无序列表中 了，那就记录当前值，一直到有序列表为止，此时后半部分的有序列表中的第一个值，也要比前面的大或等于前面的最大值，记录下的位置值就不会再改动了，从右到左的部分类似
    for (int i = 1; i < len; i++) {
		maxNum = max(maxNum, nums[i]);
		minNum = min(minNum, nums[len - 1 - i]);
		if (nums[i] < maxNum) low = i;
		if (nums[len - 1 - i] > minNum) high = len - 1 - i;
	}

	return low > high ? low - high + 1 : 0; //计算中间位置
}

}; 
