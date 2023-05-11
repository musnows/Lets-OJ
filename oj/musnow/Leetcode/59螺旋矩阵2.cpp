class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> nums(n,vector<int>(n,0));//初始化
        int start_x=0,start_y=0;//从左上角开始
        int round = n/2;//搞几圈
        int mid = n/2;//中间位置的下标（如果是奇数）
        int count = 1;//赋值
        int offset=1;//控制边的长度
        int i,j;
        while(round--)//跑的圈数
        {
            i = start_x;
            j = start_y;

            //从左上开始填充第一行
            for(j=start_y;j<n-offset;j++)
            {
                nums[i][j] = count++;
            }
            //从右上往下填充右侧列
            for(i=start_x;i<n-offset;i++)
            {
                nums[i][j] = count++;
            }
            //第一个省略，代表i和j沿用上面的末尾值
            //从右下往左填充底行
            for(;j>start_y;j--)
            {
                nums[i][j] = count++;
            }
            //从左下网上填充列
            for(;i>start_x;i--)
            {
                nums[i][j] = count++;
            }

            //00开始搞定了，要从11开始
            start_x++;
            start_y++;
            //偏移量也需要加多一位
            offset++;
        }
        if(n%2)//奇数，填充最中间的
        {
            nums[mid][mid] = count;
        }
        return nums;
    }
};
//https://leetcode.cn/problems/spiral-matrix-ii/submissions/