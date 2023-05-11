//https://leetcode.cn/problems/pascals-triangle/
//118. 杨辉三角 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     vector<vector<int>> vv;
     vv.resize(numRows);//开辟n行数组
     //初始化
     for(int i=0;i<vv.size();i++)
     {   
         //杨辉三角，每行个数递增
          vv[i].resize(i+1,0);
          
          //初始化每一行的首个和最后一个
          vv[i][0]=1;
          vv[i][vv[i].size()-1]=1;
     }
    
    //遍历杨辉三角，生成中间数字
    for(int i=0;i<vv.size();i++)
    {
        for(int j=0;j<vv[i].size();j++)
        {    
            //中间的数字（等于i-1行的j-1的数字和i-行的j的数字相加）
            if(vv[i][j]==0)
            vv[i][j]=vv[i-1][j-1]+vv[i-1][j];
        }
    }
    return vv;
    } 
};
