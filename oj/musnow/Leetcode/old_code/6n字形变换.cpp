class Solution {
public:
    // 奇数行，最中间的
    // 5 -> 2 | 7 -> 3
    bool isMidRow(int n,int numRows)
    {
        return (numRows%2!=0) && n == numRows/2;
    }
    bool isFirstEnd(int n,int numRows)
    {
        return n==0 || n==numRows-1;
    }

    string convert(string s, int numRows) {
        if(numRows<=1)
        {
            return s;
        }
        string ret;
        int begin_sep = (numRows-1)*2;
        int sep = begin_sep;// 第一行和最后一行都是这个长度
        // 中间的是从第一行开始，每次-2
        
        // 开始遍历，排除最后一行
        for(int i=0;i<numRows;i++)
        {
            if(i==numRows-1){
                sep = begin_sep;// 最后一行的长度分割
            }
            int index = i;
            int reverFlag = 1;
            int cur_sep = sep;
            while(index<s.size()){
                ret+=s[index];
                //是否是单数行中间的，如果是那就不需要反转
                if(isMidRow(i,numRows) || isFirstEnd(i,numRows)){
                    index+=sep;
                    //cout << i << " continue" << endl;
                    continue;
                }
                else if(reverFlag == 1){//本行第一次进来
                    index+=sep;
                    //cout << i << " 1r-sped "<<sep<<endl;
                    //int reverNum = abs((numRows/2-1)*2);
                    //cout << i << " 1r-rever "<<reverNum <<endl;
                    // 4行，上对称行第一次翻转是-2
                    // 5行，上对称行第一次反转是-4
                    int k = numRows - i - 1;
                    if(i<(numRows/2))//上对成行
                    {
                        //获取对称的行号的sep，并计算两者差值
                        reverFlag = - abs((begin_sep - k*2) - cur_sep);
                    }
                    else
                    {
                        reverFlag = abs((begin_sep - k*2) - cur_sep);
                    }
                    //cout <<i <<" 1r-flag "<<reverFlag<<endl;
                }
                else//第二次，开始反转
                {
                    cur_sep += reverFlag;
                    index+= cur_sep;
                    //cout <<i <<" sepd "<<( cur_sep)<<endl;
                    reverFlag = -reverFlag;//逆置
                    //cout <<i <<" flag "<<reverFlag<<endl;
                }
            }
            // 一行走完了，更新sep
            sep-=2;
        }

        return ret;
    }
};
//https://leetcode.cn/problems/zigzag-conversion/