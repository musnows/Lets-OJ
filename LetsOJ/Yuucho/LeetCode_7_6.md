# 5. 最长回文子串

[5. 最长回文子串 - 力扣（LeetCode）](https://leetcode.cn/problems/longest-palindromic-substring/)

动态规划，我们用二维数组`f[i][j]`去记录字符串s[i~j]子区间是否为回文串。

首先区间只有一个字符时肯定是回文串，记为true，其余记为false。

如果s[i]=s[j]，就继续判断s[i+1]是否等于s[j-1]，依次迭代下去，判断出`f[i][j]`是否为true即子区间s[i-j]是否为回文串。

如果`f[i][j]`为true且s[i-1]==s[j+1],我们就可以推论出`f[i-1][j+1]`为true。

这其实动态规划的一种转移，这种转移的时间复杂度是O(1)，但是我们仍然要枚举i、j，只是优化了双指针向中间转移的代价，所以总体的时间复杂度是O(n^2).

![image-20220706114254325](https://img-1311912725.cos.ap-guangzhou.myqcloud.com/images/202207061213257.png)

```C++
class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.length();
        vector<vector<bool>> f(n, vector<bool>(n, false));
        int maxlen = 1, st = 0;
        //区间只有一个字符为true
        for(int i = 0; i < n; ++i){
            f[i][i] = true;
        }
        
        //从长度为2的子区间开始枚举
        for(int len = 2; len <= n; ++len){
            //i为左端点
            for(int i = 0; i + len <= n; ++i){
                //j为右端点
                int j = i + len - 1;
                //如果左右端点不相等，跳过本次循环
                if(s[i] != s[j]) continue;
                //如果len=2左右端点会交错
                if(len > 2 && !f[i+1][j-1]) continue;
                f[i][j] = true;
                maxlen = len;
                st = i;
            }
        }
        return s.substr(st, maxlen);
    }
};
```

# 11 盛最多水的容器

#### [盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/)

双指针算法。要确保双指针算法的可行性，就必须证明指针不需要回退。证明结果如下：

![image-20220706223604206](https://img-1311912725.cos.ap-guangzhou.myqcloud.com/images/202207062236036.png)

```C++
class Solution {
public:
    int maxArea(vector<int>& height) {
		int n = height.size();
        int l = 0, r = n - 1;
        int ret = 0;
        
        while(l < r){
            int ans = min(height[l], height[r]) * (r - l);
            ret = max(ret, ans);
            
            //矮柱向中间靠拢
            if(height[l] < height[r]) l++;
            else r--;
        }
        return ret;
    }
};
```

# 15 三数之和

#### [三数之和](https://leetcode.cn/problems/3sum/)

(1)暴力枚举每一个元素

(2)双指针：为什么能用双指针这个和两数之和的证明是一样的。

先固定一个值a[i]，然后双指针去剩余的两个元素，那么此时这道题就变成了两数之和。

(3)要求我们找出每一个不重复的答案

要解决这个问题，首先我们在枚举a[i]的时候就不应该重复。

其次，如果我们找到了两组不同的答案，如果两组之间存在相同的值，那么另外两个数字也一定相等。所以我们不能让a[L] = a[L']。此时我们跳过和a[L]相同的元素。

同理，如果 a[L] != a[L'],那么必然a[R] !=a[R'] .

![image-20220706230417216](https://img-1311912725.cos.ap-guangzhou.myqcloud.com/images/202207062304371.png)

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		int n = a.size();
        vector<vector<int>> ret;
        sort(a.begin(), a.end());
        
        //暴力枚举，确定第一个元素
        //避免枚举同一个元素
        
        int preid = -1;
        for(int i = 0; i < n; ++i){
            //a[i] 暴力枚举的第一个元素
            
            //避免枚举同一个元素
            if(preid != -1 && a[i] == a[preid]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                int sum = a[i] + a[l] + a[r];
                if(sum == 0){
                    ret.push_back({a[i], a[l], a[r]});
                    int v = a[l];
                    while(l < r && a[l] == v) ++l;//a[i] != v
                }else if(sum < 0){
                    ++l;
                }else{
                    --r;
                }
            }
            preid = i;
		}
        return ret;
    }
};
```

# 17 电话号码的字母组合

#### [电话号码的字母组合](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/)

递归，很简单，我们直接看代码理解。

```C++
class Solution {
public:
    void dfs(const string& digit, int cur, string t, const vector<string>& list, vector<string>& ret) {
        //数字序列枚举完了
        if (cur == digit.length()) {
            if (!t.empty()) ret.push_back(t);
            return;
        }
		//否则计算一下对应的字符序列的下标
        //偏移量是2
        int idx = digit[cur] - '0' - 2;
        //枚举
        for (char c : list[idx]) {
            dfs(digit, cur+1, t+c, list, ret);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        //特判空串
        if(digits.empty()) return ret;
        
        vector<string> list{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string t;
        //数字序列从0开始枚举
        //把每一个数字对应的字符序列传进去
        //t是枚举的结果(一开始是空串)用ret来保存
        dfs(digits, 0, t, list, ret);
        return ret;
    }
};
```

