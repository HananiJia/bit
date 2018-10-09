#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		//0-9 1
		//10-18 2
		//19-25 3
		vector<string> ret;
		vector<char> fir = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
		for (int i = 0; i < words.size(); i++)
		{
			set<int> arr;
			string temp = words[i];
			int m = 0;
			while (char n = temp[m])
			{
			
				if (n >= 'A'&&n <= 'Z')
				{
					n = n + 32;
				}
				int k = 0;
				for ( k = 0; k < fir.size(); k++)
				{
					if (fir[k] == n)
					{
						break;
					}
				}
				if (k >= 0 && k <= 9)
					arr.insert(1);
				else
				{
					if (k >= 10 && k <= 18)
						arr.insert(2);
					else
					{
						arr.insert(3);
					}
				}
				if (arr.size() >= 2)
					break;
				m++;
			}
			if (arr.size() == 1)
			{
				ret.push_back(temp);
			}
		}
		return ret;
	}
};