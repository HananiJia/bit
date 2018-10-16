#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:

	// Encodes a URL to a shortened URL.
	//https://leetcode.com/problems/design-tinyurl
	//http://tinyurl.com/4e9iAk
	string encode(string longUrl) {
		int n = 8;
		string NewUrl;
		for (int i = 0; i <= 8; i++)
		{
			NewUrl[i] = longUrl[i];
		}
		n++;
		char temp = longUrl[n];
		while (temp)
		{
			int m = n;
			if (temp == longUrl[n + 1])
			{
				NewUrl[n++] = 2;
				NewUrl[n] = temp;
			}
			else
			{
				NewUrl[n] = temp;
			}
			n++;
			temp = NewUrl[n];
		}
		return NewUrl;


	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		int n = 8;
		string NewUrl;
		for (int i = 0; i <= 8; i++)
		{
			NewUrl[i] = shortUrl[i];
		}
		n++;
		char temp = shortUrl[n];
		while (temp)
		{
			int m = n;
			if (temp == 2)
			{
				NewUrl[n++] =temp;
				NewUrl[n] = temp;
			}
			else
			{
				NewUrl[n] = temp;
			}
			n++;
			temp = NewUrl[n];
		}
		return NewUrl;
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));