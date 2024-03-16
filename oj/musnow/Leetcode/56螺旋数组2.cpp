class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 构造的时候就需要把空间开好
        vector<vector<int>> retV(n,vector<int>(n)); 

        int count = 1;
        int loop = n/2; // 一共需要转几圈？
        int startX = 0, startY = 0;
        int offset = 1; //第一层遍历的时候只需要遍历N-1次，越往内遍历次数会减少
        int i,j; // 预先定义才能在循环外部使用
        while(loop--)
        {
            i = startX; // 横着的
            j = startY; // 竖着的

            // 从左往右边
            for(i = startX;i<n-offset;i++)
            {
                retV[j][i] = count++;
            }
            // 最右侧从上往下
            for(j = startY;j<n-offset;j++)
            {
                retV[j][i] = count++;
            }
            // 右下角从右往左
            for(;i>startX;i--){
                retV[j][i] = count++;
            }
            // 左下角从下往上
            for(;j>startY;j--){
                retV[j][i] = count++;
            }

            // 更新起始点，从0,0更新到1,1
            startX++;
            startY++;
            // 下一次遍历需要走的步数会减一，对应offset加一
            offset++;
        }

        // 奇数还有中间的那个没有处理
        if(n%2==1){
            int mid = n/2; // 中间位置的下标
            retV[mid][mid] = count;
        }
        return retV;
    }   
};

// https://leetcode.cn/problems/spiral-matrix-ii/