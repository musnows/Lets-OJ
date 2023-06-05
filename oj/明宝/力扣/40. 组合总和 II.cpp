// https://leetcode.cn/problems/combination-sum-ii/description/
// 40. 组合总和 II
// https://www.programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html#%E5%9B%9E%E6%BA%AF%E4%B8%89%E9%83%A8%E6%9B%B2 

class Solution {
public:
// 这题难点在于如何去重
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool> used)
    {
        if(target == sum)
        {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i<candidates.size() && target>=sum+candidates[i]; i++)
        {
            // 去重,相同的数用过时要跳过，used为true时代表说明同一树枝candidates[i - 1]使用过，used为false代表同一树层candidates[i - 1]使用过
            if(i>0 && candidates[i]==candidates[i-1] && used[i-1]==false)
                continue;
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum+candidates[i], i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};
// 方法二：startIndex来去重
vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex)
    {
        if(target == sum)
        {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i<candidates.size() && target>=sum+candidates[i]; i++)
        {
            // 去重
            if(i>startIndex && candidates[i]==candidates[i-1])// 这说明之前与之相同的数已经作为这层所选被下层接收了，再选一次会重复
                continue;
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum+candidates[i], i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
 
