#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Stack_HW1.h"
#include <fstream>
#include <ctime>
#include <iomanip>

#define ASSERT_OK \
	if(!this->Ok()) \
	{ \
		this->Dump(); \
		printf("Stack is damaged!\n"); \
	}


Stack::Stack() : size_(0)
{
	printf("Stack's default constructor is working\n");
	for (unsigned int i = 0;i < (int)capacity_;i++)
		data_[i] = POISON_FLOAT;
}

Stack::~Stack()
{
	printf("Stack's default destructor is working\n");
}

bool Stack::Push(value_type value)
{
	ASSERT_OK;
	if (size_ >= capacity_)
	{
		ASSERT_OK;
		return false;
	}
	data_[size_] = value;
	size_++;
	ASSERT_OK;
	return true;
}

void Stack::Pop()
{
	ASSERT_OK;
	if (size_ > 0)
	{
		data_[size_] = POISON_FLOAT;
		size_--;
	}
	else
	{
		//????????????????
	}
	ASSERT_OK;
	return;
}

Stack::value_type Stack::Top() const
{
	ASSERT_OK;
	if (size_ > 0)
	{
		return data_[size_-1];
	}
	else
	{
		return POISON_FLOAT;
	}
}

size_t Stack::Capacity() const
{
	ASSERT_OK;
	if(Ok()) return size_;
	//что в противном случае?
}

bool Stack::Empty() const
{
	ASSERT_OK;
	if (size_ == 0) return true;
	else return false;
}

bool Stack::Ok() const
{
	if ((size_ <= capacity_) && (size_ >= 0)) return true;
	else return false;
}

void Stack::Dump() const
{
	std::ofstream dumpfile("Dump.txt", std::ios_base::app);
	if (!dumpfile.is_open())
	{
		printf("Cannot open Dump.txt");
		return;
	}
	dumpfile << "--------------------------------------------------------------\nNew call of Dump()\n";
	std::time_t result = std::time(NULL);
	dumpfile << std::asctime(std::localtime(&result));
	dumpfile << "\n\n";
	dumpfile << "Stack " << " ok(" << Ok() << ")\n";
	dumpfile << "size_ = " << size_ << "\n";
	dumpfile << "capacity_ = " << capacity_ << "\n";
	dumpfile << "data [" << capacity_ << "]:";
	dumpfile << "{\n";
	for (size_t i = 0; i < capacity_; i++)
	{
		dumpfile << "[" << i << "] = " << data_[i] << "\n";
	}
	dumpfile << "}\n";
	dumpfile.close();
}
