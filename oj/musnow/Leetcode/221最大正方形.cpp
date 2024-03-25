class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        // 用于记录前缀和，下标代表这个数的行之前以及列以上的1的个数（不包括数本身）
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<pair<int, int>>> oneCount(
            n, vector<pair<int, int>>(m, {0, 0}));
        oneCount[0][0] = {0, 0};
        // O(M*N)
        for (int i = 0; i < matrix.size(); i++) {
            int count = 0; // 行1计数
            for (int j = 0; j < matrix[i].size(); j++) {
                // 第i行，j之前的1的个数（不包括当前值）
                oneCount[i][j].first = count; // 先赋值，因为不包括自己
                // 第i行，第j列往上1的个数（不包括当前值）
                if (i == 0) {
                    oneCount[i][j].second = 0;
                } else {
                    // 直接拿上一层的值，再判断上一层是否为1
                    oneCount[i][j].second = oneCount[i - 1][j].second;
                    if (matrix[i - 1][j] == '1') {
                        oneCount[i][j].second++;
                    }
                }

                // 每一行的1的个数加一
                if (matrix[i][j] == '1') {
                    count++;
                }
            }
        }

        // 此时可以得到一个矩阵，这样判断是否为正方形只需要判断对角线的数
        int maxSquare = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    int a = i + 1, b = j + 1;
                    int length = 1;      // 当前正方形边长
                    int lengthCheck = 1; // 判断计数器
                    while (a < matrix.size() && b < matrix[i].size()) {
                        pair<int, int> p = oneCount[a][b];
                        p.first -=
                            oneCount[a][b - lengthCheck].first; // 行的前一个
                        p.second -=
                            oneCount[a - lengthCheck][b].second; // 列的上一个
                        // printf("ij:[%d,%d] ab:[%d,%d] p:{%d,%d} l:%d\n",i,j,a,b,p.first,p.second,length);
                        // 符合正方形要求
                        if (matrix[a][b] == '1' && (p.first == lengthCheck &&
                                                    p.second == lengthCheck)) {
                            lengthCheck++;
                            length++;
                        } else {
                            break; // 不符合就跳出
                        }
                        a++;
                        b++;
                    }
                    int square = length * length;
                    maxSquare = square > maxSquare ? square : maxSquare;
                }
            }
        }
        return maxSquare;
    }
};