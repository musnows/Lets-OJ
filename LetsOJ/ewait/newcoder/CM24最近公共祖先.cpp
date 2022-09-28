class LCA {
  public:
    //CM24 最近公共祖先
    //https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
    //
    //将一棵无穷大满二叉树的结点按根结点一层一层地从左往右编号，根结点编号为1。现给定a，b为两个结点。设计一个算法，返回a、b最近的公共祖先的编号。注意其祖先也可能是结点本身。
    int getLCA(int a, int b) {
        // write code here
        int A = a, B = b;
        int pA = A / 2;
        int pB = B / 2;
        cout <<"begin: " << pA << " " << pB << endl;
        while (pB > 0 && pA > 0) 
        {
            while (pB > pA && pA > 0)
            {
                cout << pA << " " << pB << endl;
                pB /= 2;
            }
            while (pA > pB && pB > 0)
            {
                cout << pA << " " << pB << endl;
                pA /= 2;
            }
            if (pB == pA)
            {
                return pB;
            }
        }
        
        cout << "end:  " << pA << " " << pB << endl;
        return 1;
    }

    //思路：
    //1.因为根是1开始的，画个图就知道，父亲=孩子/2
    //2.那么就只需要循环一直除，直到两边的父亲相等的时候return
    //3.如果遇不到两边相等的情况，说明他们的祖父是1，即根节点
    //注意，必须要套两层循环进行/=2操作，不能粗暴的将pb和pa同时/2。这可能会导致某些情况直接被跳过，就找不到本来有的公共祖先了
    //比如第一次/2后，a的父亲是6，b的父亲是3
    //这时候只要把a的父亲/2，就能得到一个公共祖先3
    //但是如果同时粗暴/2，那就会变成3和1，直接错过了3的情况，err
};
