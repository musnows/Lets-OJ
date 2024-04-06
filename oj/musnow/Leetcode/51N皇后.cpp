class Solution {
    vector<vector<string>> retV;
    // n是皇后数量（同时也是棋盘的边长），row是行号
    void _solveNQueens(int n, int row, vector<string>& curV) {
        // 行号是下标，当下标row等于n的时候代表越界，找到了一个解
        if (n == row) {
            retV.push_back(curV);
            return;
        }
        // 列号，每一位都尝试使用
        for (int col = 0; col < n; col++) {
            // 判断是否符合条件，不符合直接返回
            if (checkQueen(curV, n, row, col) == false) {
                continue; // 后面可能有符合条件的，不能return
            }
            curV[row][col] = 'Q'; // 假设为皇后
            row++;                // 下一行
            // 递归
            _solveNQueens(n, row, curV);
            // 回溯
            row--;
            curV[row][col] = '.'; // 重置
            // row--; // error，应该先减减再重置数组中的值
        }
    }
    // 注意，每一次选择都需要做检查，判断同一行，同一列，斜线上是否有其他皇后
    // 入参是当前插入皇后的位置
    bool checkQueen(const vector<string>& curV, int n, int row, int col) {
        // 因为在回溯每一层的时候都只会选择一行进行处理，一行只会有一个Q，不需要遍历
        // 遍历列（这里小于row就行了，因为回溯才走到这里，更大的行是没有数据的）
        for (int i = 0; i < row; i++) {
            if (curV[i][col] == 'Q') {
                return false;
            }
        }
        // 遍历右边斜线（从右上到左下的斜线,135°）
        // 减一开始往回遍历
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (curV[i][j] == 'Q') {
                return false;
            }
        }
        // 遍历左边斜线，45°
        // 这里应该是列加一行减一，然后每一次都是行减一列加一
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (curV[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 1) {
            retV.push_back(vector<string>{"Q"});
            return retV;
        }
        // 注意vector需要初始化，不然没有办法直接下标操作
        vector<string> curV(n, string(n, '.'));
        _solveNQueens(n, 0, curV);
        return retV;
    }
};