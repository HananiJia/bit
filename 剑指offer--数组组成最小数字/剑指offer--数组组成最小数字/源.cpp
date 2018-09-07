#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		int length = numbers.size();//�����鳤��
		//��һ����
		int i = 0;
		int j = 0;
		for (; i < length; i++)
		{
			for (j = 0; j < length - i - 1; j++)
			{
				if (numbers[j]>numbers[j + 1])
				{
					int temp = numbers[j];
					numbers[j] = numbers[j + 1];
					numbers[j + 1] = temp;
				}
			}
		}
		int num = 0;
		for (i = 0; i < length; i++)
		{
			num = num + numbers[i] * pow(10, length - 1 - i);
		}
		return num;
	}
};




/*��vector�����ڵ����ݽ������򣬰��� ��a��bתΪstring��
�� a��b<b+a  a������ǰ �Ĺ�������,
�� 2 21 ��Ϊ 212 < 221 ���� �����Ϊ 21 2
to_string() ���Խ�int ת��Ϊstring
*/ 
class Solution {
public:
	static bool cmp(int a, int b){
		string A = to_string(a)+to_string(b);
		string B = to_string(b)+to_string(a);
		return A < B;
	}
	string PrintMinNumber(vector<int> numbers) {
		string answer = " ";
		sort(numbers.begin(), numbers.end(), cmp);
		int i = 0;
		for (; i < numbers.size(); i++)
		{
			answer += to_sting(numbers[i]);
		}
		return answer;
	}
};
template <class _RandomAccessIter>
inline void sort(_RandomAccessIter __first, _RandomAccessIter __last) {
	__STL_REQUIRES(_RandomAccessIter, _Mutable_RandomAccessIterator);
	__STL_REQUIRES(typename iterator_traits<_RandomAccessIter>::value_type,
		_LessThanComparable);
	if (__first != __last) {
		__introsort_loop(__first, __last,
			__VALUE_TYPE(__first),
			__lg(__last - __first) * 2);
		__final_insertion_sort(__first, __last);
	}
}

template <class Size>
inline Size __lg(Size n) {
	Size k;
	for (k = 0; n > 1; n >>= 1) ++k;
	return k;
}

template <class _RandomAccessIter, class _Tp, class _Size>
void __introsort_loop(_RandomAccessIter __first,
	_RandomAccessIter __last, _Tp*,
	_Size __depth_limit)
{
	while (__last - __first > __stl_threshold) {
		if (__depth_limit == 0) {
			partial_sort(__first, __last, __last);
			return;
		}
		--__depth_limit;
		_RandomAccessIter __cut =
			__unguarded_partition(__first, __last,
			_Tp(__median(*__first,
			*(__first + (__last - __first) / 2),
			*(__last - 1))));
		__introsort_loop(__cut, __last, (_Tp*)0, __depth_limit);
		__last = __cut;
	}
}

template <class _RandomAccessIter, class _Tp>
_RandomAccessIter __unguarded_partition(_RandomAccessIter __first,
	_RandomAccessIter __last,
	_Tp __pivot)
{
	while (true) {
		while (*__first < __pivot)
			++__first;
		--__last;
		while (__pivot < *__last)
			--__last;
		if (!(__first < __last))
			return __first;
		iter_swap(__first, __last);
		++__first;
	}
}