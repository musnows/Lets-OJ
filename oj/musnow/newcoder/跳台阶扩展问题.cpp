//其实就是找一下规律，这个规律比我自己想的更简单
//1 1种
//2 2种 1 2
//3 4种 111 12 21 3
//4 8种 1111 22 121 211 112 13 31 4
//所以就是2的n-1次方
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number int整型 
     * @return int整型
     */
    int jumpFloorII(int number) {
        // write code here
        int ret=pow(2,number-1);
        return ret;
    }
};
