class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }
        // 按左边界升序排序
        sort(intervals.begin(), intervals.end(), cmp);
        // 直接统计重叠区间有哪些
        int count = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            // 重叠区间
            if (intervals[i][0] < end) {
                count++;
                // 重叠的时候，需要更新最小的边界值
                // 因为我们假设移除那个边界值更大的节点，这样就能最大限度的避免重叠
                // 比如[[1,2],[2,3],[3,4],[1,3]]中，1,2和1,3重叠，我们应该移除1,3才是正确的
                // 此时就应该将2作为边界值继续判断，相当于保留1,2节点
                end = min(intervals[i][1],end);
            } else // 不重叠，更新边界值
            {
                end = intervals[i][1];
            }
        }
        return count;
    }
};
