class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1.所有油加起来没有距离长，说明永远走不到
        // 2.假设从0开始，走到i，如果剩余油为负数，说明[0,i]区间内，不管从哪里开始，都走不到i；
        //   那么就需要从i+1开始重新走，直到剩余油再次为负数或者走完整个区间
        int start = 0;
        int totalSum = 0;
        int leftGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            leftGas += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if (leftGas < 0) {
                // 因为[start,i]区间内剩余油是负数，说明从这个区间任意位置开始都走不到i
                // 所以需要从i+1作为一个新的起点，继续往后走。
                start = i + 1; 
                leftGas = 0; // 重置剩余油
                // 会不会出现i+1越界了的情况？这种情况说明i=size-1的时候，leftGas小于0；
                // 同时也说明了[start,sz-1]还是无法走完，反应到全局说明油本来就是不够的；
                // 此时会在后面的totalSum的判断中返回-1，所以不会出现start越界的情况；
            }
        }
        // 如果diff加起来最终是个负数，说明油是不够用的
        if (totalSum < 0) {
            return -1;
        }
        return start;
    }
};