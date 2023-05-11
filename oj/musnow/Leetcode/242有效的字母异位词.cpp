class Solution {
public:
    bool isAnagram(string s, string t) {
        //哈希映射26个字母到数组中
        vector<int> cmp1(26,0);
        vector<int> cmp2(26,0);
        for(auto& c:s)
        {
            cmp1[c-'a']++;
        }
        for(auto& c:t)
        {
            cmp2[c-'a']++;
        }

        for(int i=0;i<cmp1.size();i++)
        {
            if(cmp1[i]!=cmp2[i])
            {
                return false;
            }
        }
        return true;
    }
};
//https://leetcode.cn/problems/valid-anagram/description/

//上面这个办法的空间复杂度更高（虽然都是O1)
//用下面的办法，第一个遍历++。第二次遍历--，节省了一个vector的空间
//时间复杂度是O(s.size()+t.size()+26),相当于O(2N),即O(N)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> nums(26,0);
        for(auto&c:s)
        {
            nums[c-'a']++;
        }
        for(auto&c:t)
        {
            nums[c-'a']--;
        }
        for(auto&n:nums)
        {
            if(n!=0)
            {
                return false;
            }
        }
        return true;
    }
};