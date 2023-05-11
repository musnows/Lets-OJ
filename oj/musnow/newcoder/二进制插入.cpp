class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        m <<=j;//左移j位
        int ret = n|m;//按位与
        return ret;//返回结果
    }
};
//给定m和n
//把m的二进制位数插入到n的二进制的第j到第i位
//保证n的第j到id位二进制都为0，m的二进制数小于等于i-j+1
//其中二进制数从0开始由低到高
