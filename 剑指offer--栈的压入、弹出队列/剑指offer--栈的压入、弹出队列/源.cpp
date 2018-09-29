#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		stack<int> s;
		int i = 0;
		int j = 0;
		int length = pushV.size();
		while (i < length)
		{
			if (pushV[i] == popV[j])
			{
				i++;
				j++;
			}
			else
			{
				if (s.empty())
				{
					s.push(pushV[i]);
					i++;
				}
				else
				{
					if (s.top() == popV[j])
					{
						s.pop();
						j++;
					}
					else
					{
						s.push(pushV[i]);
						i++;
					}
				}
			}
		}
		if (j < length)
		{
			while (!s.empty())
			{
				if (popV[j] == s.top())
				{
					s.pop();
					j++;
				}
				else
				{
					return false;
				}
			}
		}
		return true;

	}
};