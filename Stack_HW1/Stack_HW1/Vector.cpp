#include "Vector.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>

Vector::Vector(): size_(0), capacity_(10)
{
	data_ = new value_type[capacity_];
	for (size_t i = 0; i < capacity_;i++)
		data_[i] = POISON_FLOAT;
}

bool Vector::Ok() const
{
	if (size_ <= capacity_) return true;
	else return false;
}

Vector::~Vector()
{
	delete[capacity_] data_;	//норм?
}

bool Vector::IsEmpty() const
{
	if (size_ == 0) return true;
	else return false;
}

Vector::value_type Vector::First() const
{
	if ((!IsEmpty()) && (Ok())) return data_[0];
	else return POISON_FLOAT;
}

Vector::value_type Vector::Last() const
{
	if ((!IsEmpty()) && (Ok())) return data_[size_-1];
	else return POISON_FLOAT;
}

bool Vector::Insert(Vector::value_type data)
{
	if (!Ok())
	{
		return false;
	}
	if (size_ == capacity_) Expand();
	data_[size_] = data;
	size_++;
	return true;
}




void Vector::Dump(std::string a) const
{
	std::ofstream dumpfile("dump.txt", std::ios_base::app);
	if (!dumpfile.is_open())
	{
		printf("Can not open Dump.txt");
		return;
	}
	dumpfile << "--------------------------------------------------------------\nDump() for class Vector\n";
	dumpfile << "Function " << a << "\n";
	std::time_t result = std::time(NULL);
	dumpfile << std::asctime(std::localtime(&result));
	dumpfile << "\n\n";
	dumpfile << "Vector " << " ok(" << Ok() << ")\n";
	dumpfile << "size_ = " << size_ << "\n";
	dumpfile << "capacity_ = " << capacity_ << "\n";
	for (size_t i = 0; i < capacity_; i++)
	{
		dumpfile << "\tdata_[" << i << "] = " << data_[i] << "\n";
	}
	dumpfile.close();
}

