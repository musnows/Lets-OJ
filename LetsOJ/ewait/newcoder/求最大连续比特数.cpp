// 求一个int类型数字的二进制最多有几个连续的1
// 00001
// 11110
//&11111
//思路：
//1用~1和这个数字去按位或，有1为1，只要末尾变成1（即-1）那么说明该数的末尾是1，继续操作
//2直到按位或的结果不为~1了，说明现在是0，则继续右移
//3遇到按位或的结果为~1了，则重复执行第一步
//4该数<=0循环结束
void TestBinaryOne()
{
    int n;
    cin >> n;
    int comp = ~1;//对1进行按位取反，获得一个末尾为0的二进制数
    cout << comp << endl;
    //进行按位与
    int m = n;
    int count=0,max=0;
    while (m>0)
    {
        int tmp = m | comp;
        cout << "tmp: " << tmp << endl;
        while (tmp != comp)
        {
            tmp = m >> 1;
            m = tmp;
            cout << "m: " << m << "  ";
            tmp |= comp;
            count++;
            cout << "tmp: " << tmp << endl;
            if (count > max) {
                max = count;
            }
        }
        count = 0;//置零
        m = m >> 1;
    }
    
    cout << "max: " << max << endl;
}
