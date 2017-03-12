//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
//! @file Array.h
//! Implements an Array class
//!
//! @author Pasha2La, 2017
//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
#include <iostream>
#include <cassert>
#define POISON_FLOAT (float)666.666
#define POISON_INT 100500
//----------------------------------
//! Array class
//----------------------------------
class Array
{
public:
	typedef float value_type;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Default constructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-
	Array();
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Silent verifier
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool Ok() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Destructor
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐-
	~Array();
	//----------------------------------
	//! Check Array on emptiness
	//----------------------------------
	bool IsEmpty() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returnes first element of Array
	//! @return first element of Array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type First() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Returnes last element of Array
	//! @return last element of Array
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	value_type Last() const;
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Insert element to Array
	//! @param data is an element to be pushed
	//! @return success of operation
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool Insert(value_type data);
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	//! Delete element of Array
	//! @param index is an element to be deleted
	//! @return success of operation
	//‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
	bool Erase(size_t index);
	//----------------------------------
	//! Dumper
	//! @param a is the name of function called Dump()
	//----------------------------------
	void Dump(std::string a) const;

private:
	size_t size_=0;
	static const size_t capacity_=10;
	value_type data_[capacity_];

	// lvalue (будет стоять слева, МОЖНО изменять, например a[i] = 1
	value_type& operator [] (int index)
	{
		assert(0 <= index && index > capacity_);
		return data_[index];
	}
	// rvalue (будет стоять справа, НЕЛЬЗЯ изменять, например c = a[i]
	const value_type& operator [] (int index) const
	{
		assert(0 <= index && index > capacity_);
		return data_[index];
	}
	/*
	bool operator ==(Array& that)
	{
		if (this->size_ != that.size_) return false;
		for (size_t i = 0;i < size_;i++)
		{
			if (this->data_[i] != that.data_[i])
				return false;
		}
		return true;
	}

	const Array& operator = (const Array& that)
	{
		if (this == &that)
			return *this;
		else
		{
			this->size_ = that.size_;
			for (size_t i = 0;i < capacity_;i++)
			{
				this->data_[i] = that.data_[i];
			}
		}
	}
};*/