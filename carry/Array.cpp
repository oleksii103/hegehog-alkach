#include "Array.h"

bool Array::checkPosition(int position, bool isAdding) const
{
	if (isAdding)
	{
		if (position > this->length + 1 || position < 0) {
			return false;
		}
		else if (&arr[position] == nullptr)
		{
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if (position > this->length || position < 0) {
			return false;
		}
		else if (&arr[position] == nullptr)
		{
			return false;
		}
		else {
			return true;
		}
	}
}

Array::Array()
{
	this->size = 1;
	this->length = 0;
	this->arr = new int[this->size];
}

Array::Array(int size)
{
	this->length = 0;
	this->size = size;
	this->arr = new int[size];
}

Array::Array(int* arr, int length, int size)
{
	if (size < length)
	{
		throw invalid_argument("length must be less than size");
	}
	this->size = size;
	this->length = length;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->length; i++)
	{
		this->arr[i] = arr[i];
	}
}

Array::Array(const Array& copy)
{
	this->size = copy.size;
	this->length = copy.length;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->length; i++)
	{
		this->arr[i] = copy.arr[i];
	}

}

Array::Array(Array&& copy)
{
	this->size = copy.size;
	this->length = copy.length;
	this->arr = copy.arr;
	copy.arr = nullptr;
	copy.length = 0;
	copy.size = 0;
}

int Array::getSize()
{
	return this->size;
}

int Array::getLength()
{
	return this->length;
}

void Array::deleteByPosition(int position)
{
	if (checkPosition(position, false))
	{
		for (size_t i = 0; i < this->length - 1; i++)
		{
			if (i >= position)
			{
				this->arr[i] = this->arr[i + 1];
				continue;
			}

			this->arr[i] = this->arr[i];
		}
		this->length--;

	}
	else {
		throw invalid_argument("index can't be more than size");
	}
}

void Array::addByPosition(int element, int position)
{
	if (checkPosition(position, true))
	{
		if (this->length + 1 < this->size)
		{
			this->length++;
			int remember = this->arr[position];
			for (size_t i = position; i < this->length - 1; i++)
			{
				int temp = this->arr[i + 1];
				arr[i + 1] = remember;
				remember = temp;
			}
			this->arr[position] = element;

		}
		else {
			this->size += 10;
			int* temporary = new int[this->length];

			for (size_t i = 0; i < this->length; i++)
			{
				temporary[i] = this->arr[i];
			}

			delete[] this->arr;
			this->arr = new int[this->size];
			for (size_t i = 0; i < position; i++)
			{
				this->arr[i] = temporary[i];
			}
			this->arr[position] = element;
			this->length++;
			for (size_t i = position + 1; i < this->length; i++)
			{
				this->arr[i] = temporary[i - 1];
			}
		}
	}
	else {
		throw invalid_argument("index can't be more than size + 1");
	}
}

void Array::Fit()
{
	this->size = this->length;
	int* temporary = new int[this->size];
	for (size_t i = 0; i < this->length; i++)
	{
		temporary[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = temporary;
}

void Array::Sort(bool byDecreasing)
{
	if (byDecreasing)
	{
		for (size_t i = 0; i < this->length; i++)
		{
			for (size_t k = 1; k < this->length; k++)
			{
				if (this->arr[k] > this->arr[k - 1])
				{
					int change = arr[k];
					arr[k] = arr[k - 1];
					arr[k - 1] = change;
				}
			}
		}
	}
	else {
		for (size_t i = 0; i < this->length; i++)
		{
			for (size_t k = 1; k < this->length; k++)
			{
				if (this->arr[k] < this->arr[k - 1])
				{
					int change = arr[k];
					arr[k] = arr[k - 1];
					arr[k - 1] = change;
				}
			}
		}
	}
}

int& Array::operator[](int index) const
{
	if (checkPosition(index, false))
	{
		return this->arr[index];
	}
	else {
		throw invalid_argument("index can't be more than size");
	}
}

Array::~Array()
{
	delete[] this->arr;
}

ostream& operator<<(ostream& out, const Array& Arr)
{
	out << "Array: [";
	for (size_t i = 0; i < Arr.length; i++)
	{
		if (i == Arr.length - 1)
		{
			out << Arr[i];
			continue;
		}
		out << Arr[i] << ", ";
	}
	out << "]";
	return out;
}

istream& operator>>(istream& in, Array& arr)
{
	return in;
}