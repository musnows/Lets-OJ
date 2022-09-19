//JZ39 数组中出现次数超过一半的数字
//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&ru=/exam/oj
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //思想：如果两个数不相等，就消去这两个数，最坏情况下，每次消去一个众数和一个非众数，那么如果存在众数，最后留下的数肯定是众数
        int cond = -1;//初始化：候选人cond = -1， 候选人的投票次数cnt = 0
        int cnt = 0;
        for (int i=0; i<numbers.size(); ++i) {//遍历数组，如果cnt=0， 表示没有候选人，则选取当前数为候选人，++cnt
            if (cnt == 0) {
                cond = numbers[i];
                ++cnt;
            }
            else {//否则，如果cnt > 0, 表示有候选人，如果当前数=cond，则++cnt，否则--cnt
                if (cond == numbers[i]) 
                    ++cnt;
                else 
                    --cnt;
            }

        }
        cnt = 0;
        for (const int k :numbers) {//直到数组遍历完毕，最后检查cond是否为众数
            if (cond == k) 
                ++cnt;
        }
        if (cnt > numbers.size() / 2) 
            return cond;
        return 0;
    }
};

