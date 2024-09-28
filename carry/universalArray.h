#pragma once

#include <iostream>

using namespace std;

template<typename T>
class UnuversalArray {
private:
	T* arr;
	int size;
	int length;

	bool checkPosition(int position, bool isAdding) const;
public:
	UnuversalArray();
	UnuversalArray(int size);
	UnuversalArray(T* arr, int length, int size);
	UnuversalArray(const UnuversalArray&);
	UnuversalArray(UnuversalArray&&);

	int getSize();
	int getLength();

	void deleteByPosition(int position);
	void addByPosition(T element, int position);

	void Fit();

	void Sort(bool byDecreasing);//за спаданням

	T& operator[](int index) const;

	friend ostream& operator<<(ostream& out, const UnuversalArray& Arr);
	friend istream& operator>>(istream& in, UnuversalArray& arr);

	~UnuversalArray();
};