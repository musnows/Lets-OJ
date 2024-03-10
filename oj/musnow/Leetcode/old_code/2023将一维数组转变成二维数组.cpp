class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret;
        if(original.size()!=(m*n)){
            return ret;//空的
        }
        int index = 0;
        ret.resize(m);
        for(int i=0;i<m;i++)
        {
            ret[i].resize(n);
            for(int j=0;j<n;j++)
            {
                ret[i][j]=original[index++];
            }
        }
        return ret;
    }
};
// 题目要求将original构造成m行n列的二维数组，不符合条件返回空数组
//https://leetcode.cn/problems/convert-1d-array-into-2d-array/description/