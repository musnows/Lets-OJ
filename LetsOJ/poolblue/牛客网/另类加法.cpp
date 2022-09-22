class UnusualAdd {
public:
    int addAB(int A, int B) { 
        int _xol=0;
        int _and =0;
        //xor 存放异或的结果，未进位的异或。 and 存放进位结果， 通过位移操作
        while(B!=0)
        {
            _xol=A^B;
            _and=(A&B)<<1;
            A=_xol;
            B=_and;
       }
        return A;
    }
};
