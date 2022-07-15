//118杨辉三角
//https://leetcode.cn/problems/pascals-triangle/submissions/
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (size_t i = 0; i < vv.size(); ++i)
		{
			// 杨辉三角，每行个数依次递增
			vv[i].resize(i + 1, 0);

			// 第一个和最后一个初始化成1
			vv[i][0] = 1;
			vv[i][vv[i].size() - 1] = 1;
		}

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					// 中间位置等于上一行j-1 和 j个相加
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}

		return vv;
	}
};