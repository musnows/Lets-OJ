class Solution {
    vector<string> retV;

    void _restoreIpAddresses(string s, int startIndex, int pointNum) {
        // IP地址需要打三个点，有三个点了之后就不需要继续for了
        if (pointNum == 3) {
            // 判断最后一部分是否符合ip的条件
            if (checkIpStr(s, startIndex, s.size() - 1)) {
                retV.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            // 判断[start,i]区间是否是合法的ip地址组成
            if (checkIpStr(s, startIndex, i)) {
                // 是，加点（注意insert是在选中位置之前插入）
                // 加点是为了方便最后直接插入返回值
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                // 这里加2是为了跳过插入的点，走到下一位
                _restoreIpAddresses(s, i + 2, pointNum);
                // 回溯本层操作
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            // 如果已经不符合条件了，说明这一层都不符合条件了
            // 比如515已经不符合条件了，再往后走更不符合（这一层符合条件的组合已经在之前走过了）
            else {
                break; // 跳出本层
            }
        }
    }

    // 判断这个区间是否是合法的ip地址
    bool checkIpStr(const string& s, int start, int end) {
        // 区间合法（不能等于，start==end时是一个数字的情况）
        if (start > end) {
            return false;
        }
        // 以0开始的不合法（除非只有一个0）
        if (s[start] == '0' && start != end) {
            return false;
        }

        int sum = 0;
        for (int i = start; i <= end; i++) {
            // 不是数字，不符合
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
            // 加到sum里面
            sum = sum * 10 + (s[i] - '0');
            // 如果超过255，不符合
            if (sum > 255) {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        _restoreIpAddresses(s, 0, 0);
        return retV;
    }
};

// https://leetcode.cn/problems/restore-ip-addresses/description/