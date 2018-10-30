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
		//这时候就很复杂了，可能最小的值被pop出去了
		//这时候就需要遍历整个栈来找出目前的最小值	
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
//		//这里的索引需要stack通过数组来实现
//		//或者在java中存在get函数接口但是在c++的stl中
//		//并没有提供获取栈指定位置的接口这里就没实现
//	}
//private:
//	stack<int> s;
//	stack<int> mini;
//}