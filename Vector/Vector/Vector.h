#pragma once 
#include<iostream>
typedef int DataType;

class Vector{
public:
	Vector()
		: _first(NULL)
		, _finish(NULL)
		, _endofstorage(NULL)
	{}
	~Vector()
	{
		if (_first)
		{

		}
	}
	Vector(const Vector v)
	{
		_first = new DataType[v.Size()];
		_finish = _first + v.Size();
		_endofstorage = _first + v.Size();
		memcpy(_first,v._first,sizeof(DataType)*v.Size())
	}
	Vector& operator=(Vector v)
	{
		swap(_first, v._first);
		swap(_finish, v._finish);
		swap(_endofstorage, v._endofstorage);
		return *this;
	}
	size_t Size() const
	{
		return _finish - _first;
	}
	size_t Capacity()
	{
		return _endofstorage - _first;
	}
	void Reverse(size_t n)
	{
		if (n > Capacity())
		{
			Expand(n);
		}
	}
	void Resize(size_t n, DataType value)
	{
		if (n < Size())
		{
			_finish = _first + n;
		}
		else
		{
			if (n>Capacity())
			{
				Expand(n);
			}
			DataType* end = _first + n;
		}
       

	}
	void PushBack(DataType x)
	{
		if (_finish = _endofstorage)
		{
			Expand(Capacity() * 2);
		}
	}
private:
	void Expand(size_t n)
	{
		if (n > Capacity())
		{
			DataType *tmp = new DataType[n];
			memcpy(_first, tmp, Size()*sizeof(DataType));
			delete[]
		}
	}
private:
	DataType* _first;
	DataType* _finish;
	DataType* _endofstorage;
};
