class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 1) {
            return 1;
        }
        // 首先需要按左边界对区间排升序
        sort(points.begin(), points.end(), cmp);
        int arrow = 1; // points 不为空至少需要一支箭
        int end = points[0][1];
        for (int i = 1; i < points.size(); i++) {
            // 重叠了，更新最小的子区间
            if (points[i][0] <= end) {
                end = min(points[i][1], end);
            } else {
                // 不重叠，需要射箭
                end = points[i][1];
                arrow++;
            }
        }
        return arrow;
    }
};
