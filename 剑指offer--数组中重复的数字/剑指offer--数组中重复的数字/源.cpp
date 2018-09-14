#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		int* hash = new int[256];
		int i = 0;
		for (i = 0; i < 256; i++)
		{
			hash[i] = 0;
		}
		for (i = 0; i < length; i++)
		{
			hash[numbers[i]]++;
		}
		int count = 0;
		for (i = 0; i < 256; i++)
		{
			if (hash[i]>1)
			{
				duplication[count++] = numbers[i];
				return true;
			}
		}
		return false;
	}
};