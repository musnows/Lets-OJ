class Solution {
public:
#define DEF -1 //默认值
    // 直接用递归会超时
    // 想法是将数据存到vector里面，避免针对某一个数的二次递归运算
    long long fib(int n,vector<int>& _map){
        if(_map[n] != DEF){
            return _map[n];
        }
        long long ans = fib(n-1,_map) + fib(n-2,_map)+fib(n-3,_map);
        _map[n] = ans;
        return ans;
    }

    int test1_tribonacci(int n) {
        vector<int> _map(40,DEF);
        _map[0] = 0;
        _map[1] = 1;
        _map[2] = 1;
        // 初始化并传引用给递归函数
        return fib(n,_map);
    }

    int test2_tribonacci(int n) {
        if(n<=1){
            return n;
        }
        vector<int> _map(n+1,DEF);
        _map[0] = 0;
        _map[1] = 1;
        _map[2] = 1;
        for(int i=3;i<_map.size();i++){
            _map[i] = _map[i-3] +_map[i-2]+_map[i-1];
        }

        return _map[n];
    }

    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        int p = 0, q = 0, r = 1, s = 1;
        for (int i = 3; i <= n; ++i) {
            p = q;
            q = r;
            r = s;
            s = p + q + r;
        }
        return s;
    }


};


//https://leetcode.cn/problems/n-th-tribonacci-number/solutions/921898/di-n-ge-tai-bo-na-qi-shu-by-leetcode-sol-kn16/