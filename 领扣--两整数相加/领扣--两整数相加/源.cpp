#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int getSum(int a, int b) {
		int all = (a&b)<<1;//�鿴����������1��λ�ã���Щλ����Ҫ��λ�ģ����������֮������һλ
		int diff = a^b;//��������鿴��������һ����1һ��û1��λ��
		while (all&diff)//�����ж���Ϊ�˷�ֹ��λ֮�����н�λ�����
		{
			a = all;
			b = diff;
			all = (a&b)<<1;
			diff = a^b;
		}
		return all | diff;//���all��diff������0˵����������û�г���ͬһλ����1�����Է���Ȼ�������������Ҳ���Ǽ�����
	}
};