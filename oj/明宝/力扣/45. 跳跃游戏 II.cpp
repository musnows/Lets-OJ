//https://leetcode.cn/problems/jump-game-ii/description/
//45. 跳跃游戏 II
// https://www.programmercarl.com/0045.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8FII.html#%E6%80%9D%E8%B7%AF

class Solution {
public:
// 贪心以最小的步数增加最大的覆盖范围，直到覆盖范围覆盖了终点，这个范围内最小步数一定可以跳到，不用管具体是怎么跳的，不纠结于一步究竟跳一个单位还是两个单位。
// 在i<curCover的途中任何一个位子都有可能需要跳到下一跳，但这不重要，在i==curCover时更新下一跳的覆盖范围就行
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        int curCover = 0;
        int nextCover = 0;
        int result = 0;
        for(int i = 0; i<=nums.size(); i++)
        {
            nextCover = max(i+nums[i], nextCover);// 更新下一步覆盖最远距离下标
            if(i==curCover)// 遇到当前覆盖最远距离下标
            {
                result++;
                curCover = nextCover;
                if(nextCover>=nums.size()-1) // 当前覆盖最远距到达集合终点，不用做ans++操作了，直接结束
                    break;
            }
        }
        return result;
    }
};

// 类似但简单的前置题 
//https://leetcode.cn/problems/jump-game/description/
//55. 跳跃游戏

//https://www.programmercarl.com/0055.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F.html#%E6%80%9D%E8%B7%AF
class Solution {
public:
// 看能跳到的区域的覆盖范围是否包含最后一个元素下标
    bool canJump(vector<int>& nums) {
        int cover = 0;
        for(int i = 0; i<=cover; i++)
        {
            cover = max(i+nums[i], cover);
            if(cover>=nums.size()-1)
            {
                return true;
            }
        }
        return false;
    }
};
