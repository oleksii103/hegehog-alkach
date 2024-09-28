#pragma once

#include <iostream>

using namespace std;

class Array {

private:

	int* arr;

	int size;

	int length;

	bool checkPosition(int position, bool isAdding) const;

public:

	Array();

	Array(int size);

	Array(int* arr, int length, int size);

	Array(const Array&);

	Array(Array&&);

	int getSize();

	int getLength();

	void deleteByPosition(int position);

	void addByPosition(int element, int position);

	void Fit();

	void Sort(bool byDecreasing);//за спаданням

	int& operator[](int index) const;

	friend ostream& operator<<(ostream& out, const Array& Arr);

	friend istream& operator>>(istream& in, Array& arr);

	~Array();

};
