#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
			{
				count++;
			}
		}
		return count;
	}
};