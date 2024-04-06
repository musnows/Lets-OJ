class Solution {
    vector<string> retV;
    // 判断是否所有机票都用完了
    bool checkTicketsEmpty(map<string, int>& tickets) {
        for (auto& p : tickets) {
            if (p.second != 0) {
                return false;
            }
        }
        return true;
    }

    // 回溯法，每一次都找一个机场走，注意起点机场是JFK
    // ticketSum是总共的机票数量，ticketNum是当前已经被使用过的机票数量
    void _findItinerary(unordered_map<string, map<string, int>>& ticketsMap,
                        const int ticketsSum, int ticketsNum,
                        const string& startAp) {
        // 如果ticket被用完了，也可以返回
        if (ticketsNum == ticketsSum) {
            return;
        }
        // 如果map里面对应的目的机场机票都用完了，这一层没有办法往下走了
        if (checkTicketsEmpty(ticketsMap[startAp])) {
            return;
        }

        // 如果不是，随机选择一个机场往下走
        for (auto& p : ticketsMap[startAp]) {
            // 跳过已经选择了的机场
            if (p.second == 0) {
                continue;
            }
            // 没有选择过，可以走
            retV.push_back(p.first);
            p.second--;   // 机票数量减一
            ticketsNum++; // 已选机票数量加一
            // cout << startAp << "->" << p.first << ":" << p.second
            //      << " num:" << ticketsNum << endl;
            _findItinerary(ticketsMap, ticketsSum, ticketsNum, p.first);
            // 符合条件了，直接跳出，地点比机票数量多一个
            if (retV.size() == ticketsSum + 1) {
                return;
            }
            // 回溯操作
            p.second++;
            ticketsNum--;
            retV.pop_back();
        }
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 存放<起点机场,<目的机场,票数>>
        // 两个机场之间单向只会有一个票，所以不需要用multimap
        unordered_map<string, map<string, int>> ticketsMap;
        for (auto& v : tickets) {
            ticketsMap[v[0]][v[1]]++;
        }
        // 因为是从JFK开始的，所以需要先把第一个值插入
        retV.push_back("JFK");
        _findItinerary(ticketsMap, tickets.size(), 0, "JFK");
        return retV;
    }
};