#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int num = 0;
//	vector<int> nums;
//	cin >> num;
//	for (int i = 0; i < num*3; i++)
//	{
//		int n;
//		cin >> n;
//		nums.push_back(n);
//	}
//	sort(nums.begin(), nums.end());
//	long long ret = 0;
//	for (int i = 1; i<=num; i++)
//	{
//		ret += nums[num * 3 - 2 * i];
//	}
//	cout << ret << endl;	
//}

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	string b;
	while (getline(cin, a))
	{
		string ret="";
		size_t pos = a.rfind(" ");
		b = a.substr(pos+1);
		a = a.substr(0, pos); 
		for (int i = 0; i < a.size(); i++)
		{
			size_t p = b.find(a[i]);
			if (p == string::npos)
			{
				ret.push_back(a[i]);
			}
		}
		cout << ret << endl;
	}	
}