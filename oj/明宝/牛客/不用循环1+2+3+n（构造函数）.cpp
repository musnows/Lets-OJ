#define _CRT_SECURE_NO_WARNINGS 
//https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1
// 求1+2+3+...+n要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句
// 调用n次构造函数
class Sum
{
public:
	Sum()
	{
		_ret += _i;// 代替循环
		++_i;
	}

	static int GetRet()
	{
		return _ret;
	}
private:
	static int _i;
	static int _ret;
};

int Sum::_i = 1;
int Sum::_ret = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		//Sum a[n];// 调用n次构造函数
		Sum* p = new Sum[n];
		return Sum::GetRet();
	}
};