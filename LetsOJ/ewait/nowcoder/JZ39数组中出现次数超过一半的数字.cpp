//JZ39 数组中出现次数超过一半的数字
//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&&tqId=11181&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz=numbers.size();
        sort(numbers.begin(),numbers.end());
        //如果超过一半，那么这个数肯定在排序后的中间
        return numbers[sz/2];
    }
};