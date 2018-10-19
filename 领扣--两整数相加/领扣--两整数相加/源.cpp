#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int getSum(int a, int b) {
		int all = (a&b)<<1;//查看两个数都有1的位置，这些位置是要进位的，所以求出来之后左移一位
		int diff = a^b;//异或用来查看两个数字一个有1一个没1的位置
		while (all&diff)//这里判断是为了防止进位之后又有进位的情况
		{
			a = all;
			b = diff;
			all = (a&b)<<1;
			diff = a^b;
		}
		return all | diff;//如果all和diff异或等于0说明两个数字没有出现同一位置有1，所以返回然后两个数字异或也就是加起来
	}
};