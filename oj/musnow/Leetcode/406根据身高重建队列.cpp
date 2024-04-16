class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        // 按身高升序排序
        if (a[0] > b[0]) {
            return true;
        }
        // 如果身高一样，前面的人少的排前面
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return false;
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 按身高降序+前面人的个数升序排列
        sort(people.begin(), people.end(), cmp);
        for (auto& v : people) {
            cout << v[0] << " " << v[1] << "\n";
        }
        vector<vector<int>> que;
        que.reserve(people.size()); // 提前开空间
        for (int i = 0; i < people.size(); i++) {
            // 前面有几个人，就往第几位插入
            int offset = people[i][1];
            que.insert(que.begin() + offset, people[i]);
        }
        return que;
    }
};
