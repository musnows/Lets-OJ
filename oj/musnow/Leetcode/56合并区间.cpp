class Solution {
	// 注意sort中升序是小于，降序是大于
    static bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> retV; // 结果集
        // 先直接把第一个元素插入
        retV.push_back(intervals[0]);
        // 从第二个元素开始遍历
        for (int i = 1; i < intervals.size(); i++) {
            // 判断当前区间是否小于结果集中上一个的边界
            if (intervals[i][0] <= retV.back()[1]) {
                // 如果小于，更新为两个值中更大的那个
                retV.back()[1] = max(intervals[i][1], retV.back()[1]);
            } else // 不小于，插入结果集
            {
                retV.push_back(intervals[i]);
            }
        }
        return retV;
    }
};
