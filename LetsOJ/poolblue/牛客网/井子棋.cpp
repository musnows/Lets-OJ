class Board {
public:
    bool checkWon(vector<vector<int> > board) {
     
      int row = board.size(); //检查每一行的和是是否等于row 
        int i,j,sum;
		 for(i=0;i<row;i++) 
        { 
            sum = 0; 
            for(j=0;j<row;j++) 
            { 
                sum += board[i][j];
            }
            if(sum==row) 
                return true;
          }//检查每一列的和是是否等于row
           for(i=0;i<row;i++) 
           {
               sum = 0; 
               for(j=0;j<row;j++)
              { 
                   sum += board[j][i];
              }
               if(sum==row) 
                   return true; 
           } //检查主对角线的和是是否等于row
          sum = 0; 
        for(i=0;i<row;i++) 
        { 
            sum += board[i][i];
        } 
        if(sum==row)
            return true; //检查副对角线的和是是否等于row 
        sum = 0; 
        for(i=0;i<row;i++) 
        {
            sum += board[i][row-i-1];
        } 
        if(sum==row) 
            return true; 
        return false;
     
    }
};
