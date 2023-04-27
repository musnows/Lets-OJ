//两个数组的交集 II
//https://leetcode.cn/problems/intersection-of-two-arrays-ii/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> m;
		vector<int> ret;
		for (auto& e : nums1)
		{
			m[e]++;
		}
		for (auto& e : nums2)
		{
			if (m.count(e))
			{
				ret.push_back(e);
				m[e]--;
				if (m[e] == 0)
					m.erase(e);
			}
		}
		return ret;
	}
};