#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;

//class Solution {
//public:
//	void push(int value) {
//		if (mini.empty()||value<=mini.top())
//		{
//			mini.push(value);
//			s1.push(value);
//		}
//		else
//		{
//			s1.push(value);
//			mini.push(mini.top());
//		}
//	}
//	void pop() {
//		if (s1.empty())
//			return ;
//		s1.pop();
//		mini.pop();
//	}
//	int top() {
//		if (s1.empty())
//			return -1;
//		return s1.top();
//	}
//	int min() {
//		if (s1.empty())
//			return -1;
//		return mini.top();
//	}
//private:
//	stack<int> s1;
//	stack<int> mini;
//};

class Solution {
public:
	void push(int value) {
		if (s.empty()||value<mini)
		{
			s.push(value);
			mini = value;
		}
		else{
			s.push(value);
		}
	}
	void pop() {
		s.pop();
		//��ʱ��ͺܸ����ˣ�������С��ֵ��pop��ȥ��
		//��ʱ�����Ҫ��������ջ���ҳ�Ŀǰ����Сֵ	
	}
	int top() {
		return s.top();
	}
	int min() {
		return mini;
	}
private:
	int mini;
	stack<int> s;
};


//class Solution {
//public:
//	void push(int value) {
//		if (mini.empty()||value<mini.top())
//		{
//			s.push(value);
//			mini.push(s.size());
//		}
//		else
//		{
//			s.push(value);
//		}
//	}
//	void pop() {
//		if (mini.top() == s.size())
//		{
//			mini.pop();
//		}
//		s.pop();
//	}
//	int top() {
//		return s.top();
//	}
//	int min() {
//		//�����������Ҫstackͨ��������ʵ��
//		//������java�д���get�����ӿڵ�����c++��stl��
//		//��û���ṩ��ȡջָ��λ�õĽӿ������ûʵ��
//	}
//private:
//	stack<int> s;
//	stack<int> mini;
//}