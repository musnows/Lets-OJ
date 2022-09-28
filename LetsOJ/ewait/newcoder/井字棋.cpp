class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // 玩家是1，0代表没有，-1是对方的棋子
        bool ret = false;
        // 1.判断横着的谁赢了
        for(int i = 0;i < board.size();i++)
        {
            vector<int> v = board[i];
            if(v[0]==1)
            {
                if(v[0]==v[1]&&v[1]==v[2]){
                    ret = true;
                }
            }
        }
        // 2.判断竖着的
        for(int i = 0;i < board[0].size();i++)
        {
            if(board[0][i]==1 && board[0][i]==board[1][i] && board[2][i]==board[1][i])
            {
                ret = true;
            }
        }
        // 3.判断斜着的
        if(board[0][0]==1)//左上角
        {
            if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
                ret = true;
            }
        }
        else if(board[0][board.size()-1]==1)//右上角
        {
            if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
                ret = true;
            }
        }
        
        return ret;
    }
    // 1 1 1   1 0 0  1 0 1
    // 0 0 1   0 1 0  1 0 0
    // 1 0 0   0 0 1  1 1 0
};
//给定一个棋盘，判断玩家是否胜利
//题目给的棋盘肯定是满的
