#include "UniversalArray.h"


template<typename T>

inline bool UnuversalArray<T>::checkPosition(int position, bool isAdding) const

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

template<typename T>

UnuversalArray<T>::UnuversalArray()

{

	this->size = 1;

	this->length = 0;

	this->arr = new T[this->size];

}

template<typename T>

UnuversalArray<T>::UnuversalArray(int size)

{

	this->length = 0;

	this->size = size;

	this->arr = new T[size];

}

template<typename T>

UnuversalArray<T>::UnuversalArray(T* arr, int length, int size)

{

	if (size < length)

	{

		throw invalid_argument("length must be less than size");

	}

	this->size = size;

	this->length = length;

	this->arr = new T[this->size];

	for (size_t i = 0; i < this->length; i++)

	{

		this->arr[i] = arr[i];

	}

}

template<typename T>

UnuversalArray<T>::UnuversalArray(const UnuversalArray&)

{

	this->size = copy.size;

	this->length = copy.length;

	this->arr = new T[this->size];

	for (size_t i = 0; i < this->length; i++)

	{

		this->arr[i] = copy.arr[i];

	}

}

template<typename T>

UnuversalArray<T>::UnuversalArray(UnuversalArray&&)

{

	this->size = copy.size;

	this->length = copy.length;

	this->arr = copy.arr;

	copy.arr = nullptr;

	copy.length = 0;

	copy.size = 0;

}

template<typename T>

int UnuversalArray<T>::getSize()

{

	return this->size;

}

template<typename T>

int UnuversalArray<T>::getLength()

{

	return this->length;

}

template<typename T>

void UnuversalArray<T>::deleteByPosition(int position)

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

template<typename T>

void UnuversalArray<T>::addByPosition(T element, int position)

{

	if (checkPosition(position, true))

	{

		if (this->length + 1 < this->size)

		{

			this->length++;

			T remember = this->arr[position];

			for (size_t i = position; i < this->length - 1; i++)

			{

				T temp = this->arr[i + 1];

				arr[i + 1] = remember;

				remember = temp;

			}

			this->arr[position] = element;

		}

		else {

			this->size += 10;

			T* temporary = new T[this->length];

			for (size_t i = 0; i < this->length; i++)

			{

				temporary[i] = this->arr[i];

			}

			delete[] this->arr;

			this->arr = new T[this->size];

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

template<typename T>

void UnuversalArray<T>::Fit()

{

	this->size = this->length;

	T* temporary = new T[this->size];

	for (size_t i = 0; i < this->length; i++)

	{

		temporary[i] = this->arr[i];

	}

	delete[] this->arr;

	this->arr = temporary;

}

template<typename T>

void UnuversalArray<T>::Sort(bool byDecreasing)

{

	if (byDecreasing)

	{

		for (size_t i = 0; i < this->length; i++)

		{

			for (size_t k = 1; k < this->length; k++)

			{

				if (this->arr[k] > this->arr[k - 1])

				{

					T change = arr[k];

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

					T change = arr[k];

					arr[k] = arr[k - 1];

					arr[k - 1] = change;

				}

			}

		}

	}

}

template<typename T>

T& UnuversalArray<T>::operator[](int index) const

{

	if (checkPosition(index, false))

	{

		return this->arr[index];

	}

	else {

		throw invalid_argument("index can't be more than size");

	}

}


template<typename T>

ostream& operator<<(ostream& out, const UnuversalArray<T>& Arr)

{

	out << "ArraysOfString: [";

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

template<typename T>

istream& operator>>(istream& in, UnuversalArray<T>& arr)

{

	return in;

}



template<typename T>

UnuversalArray<T>::~UnuversalArray()

{

	delete[] this->arr;

}
