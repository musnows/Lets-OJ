class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (groupSize == 1) {
            return true;
        }
        if (hand.size() % groupSize != 0) {
            return false;
        }
        sort(hand.begin(), hand.end());

        int w = groupSize;
        int curBegin = 0, nextBegin = 0;
        vector<int> curV;
        vector<bool> used(hand.size(), false);
        int i = 0;
        while (i < hand.size() && nextBegin < hand.size()) {
            curBegin = nextBegin;
            for (i = curBegin; i < hand.size(); i++) {
                cout << i << " - " << hand[i] << " - " << used[i] << endl;
                if (used[i] == true) {
                    continue;
                }
                if (curV.size() > 0 && hand[i] == curV[curV.size() - 1]) {
                    // 下一次开始还没有被修改过，才去修改
                    // 不然说明这一次循环遇到了两次相同元素的情况，需要跳过第二种情况
                    if (nextBegin == curBegin) {
                        nextBegin = i;
                        cout << "nextBegin: " << curBegin << " " << nextBegin
                             << endl;
                    }
                    continue;
                }
                // 不是顺子，直接返回错误
                if (curV.size() > 0 && hand[i] != curV[curV.size() - 1] + 1) {
                    cout << "return false\n";
                    return false;
                }

                curV.push_back(hand[i]);
                used[i] = true;
                if (curV.size() == w) {
                    break;
                }
            }
            // 内部因为其他错误退出
            cout << curBegin << " sz " << curV.size() << endl;
            if (curV.size() != w) {
                return false;
            }
            // 清空数组
            curV.clear();
            // 这一轮里面没有出现漏掉的，说明只剩数组后面部分的内容了
            if (curBegin == nextBegin) {
                nextBegin = i + 1;
            }
            cout << "end for:  " << curBegin << " " << nextBegin << endl;
        }
        return true;
    }
};

// https://leetcode.cn/problems/hand-of-straights/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
// 华为实习一面手撕，没写出来