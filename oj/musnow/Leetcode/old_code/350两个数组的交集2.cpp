ass Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> v;
        for(auto e: nums1)
        {
            auto it = m.find(e);
            if(it !=m.end())
            {
                it->second++;
            }
            else
            {
                m.insert(make_pair(e,1));
            }
        }
        for(auto e: nums2)
        {
            auto it = m.find(e);
            if(it !=m.end() && it->second>0)
            {
                v.push_back(it->first);
                it->second--;
            }
        }
        
        return v;
    }
};

//https://leetcode.cn/problems/intersection-of-two-arrays-ii/
//350两个数组的交集2
