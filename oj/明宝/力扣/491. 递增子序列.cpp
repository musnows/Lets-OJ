//491. 递增子序列
//https://leetcode.cn/problems/non-decreasing-subsequences/description/
// https://www.programmercarl.com/0491.%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF

class Solution {
public:
// 难点在于不能排序！而是在已有顺序里找递增的部分
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        if(path.size()>1)
        {
            result.push_back(path);
            // 千万不能加return，因为要取树上节点！！！
        }

        unordered_set<int> uset;// 用set对本层元素去重
        for(int i = startIndex; i<nums.size(); i++)
        {
            // 两种情况下要跳过：不是递增；有重复元素
            if((!path.empty() && nums[i]<path.back()) 
            || uset.find(nums[i])!=uset.end()) 
                continue;
            uset.insert(nums[i]);// 记录这个元素在本层用过了，本层后面不能再用了！因为每层递归都会创建新的uset，所以不用对应的pop
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};


// 比起用哈希表，用数组去重更快
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex)
    {
        if(path.size()>1)
            result.push_back(path);

        int used[201] = {0};
        for(int i = startIndex; i<nums.size(); i++)
        {
            if((!path.empty() && nums[i]<path.back())
            || used[100+nums[i]]==1)
                continue;
            used[100+nums[i]] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
