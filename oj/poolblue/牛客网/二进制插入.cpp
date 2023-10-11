class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        //只需左移j位然后整体相或可以得到
        return n | (m << j);
    }
};
