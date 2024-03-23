class Solution {
    
    void _combinationSum3(int k, int n,int start,int sum, vector<int> curV,vector<vector<int>>& retV ) { 
        if(curV.size() == k){
            if(sum == n){
                retV.push_back(curV);
            }
            return;
        }
        // 已经不符合条件，不进入循环
        if(sum > n){
            return;
        }
        // 一次遍历
        for(int i = start;i<=9 -(k-curV.size()-1);i++)
        {
            // 已经不符合条件，进入下一层
            if(sum + i > n){
                return; // 加i都已经超过n了，下一个数也没有必要遍历了
            }
         
            curV.push_back(i);
            _combinationSum3(k,n,i+1,sum+i,curV,retV);
            curV.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> retV;
        _combinationSum3(k,n,1,0,vector<int>(),retV);
        return retV;
    }
};

// https://leetcode.cn/problems/combination-sum-iii/description/