#define _CRT_SECURE_NO_WARNINGS 1

class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		str += ch;
		hash[ch ]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int i = 0;
		for (i = 0; i < str.size(); i++)
		{
			if (hash[str[i]] == 1)
				return str[i];
		}
		return '#';
	}
	int hash[256] = { 0 };
	string str;
};