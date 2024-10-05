#include <iostream>

template<typename T>
class Stack {
	T* array;
	int length;
	int size;
public:
	Stack() {
		array = new T[10];
		length = 0;
		size = 10;
	}
	void push(T elem) {
		if (length == size) {
			T* newArr = new T[size * 2];
			size *= 2;
			for (int i = 0; i < length; ++i) {
				newArr[i] = array[i];
			}
			newArr[length] = elem;
			length++;
			delete[] array;
			array = newArr;
		}
		else {
			array[length] = elem;
			length++;
		}
	}

	T pop() {
		if (length == 0) {
			std::cout << "Error";
			throw std::invalid_argument("Invalid syntax.");
		}
		T temp = array[length - 1];
		length--;
		return temp;
	}

	T peek() {
		if (length != 0) {
			return array[length];
		}
	}
};

int main() {
	Stack<int> st;
	st.push(1);
	st.push(11);
	st.push(12);
	st.push(13);
	st.push(14);
	st.push(15);
	st.push(16);
	st.push(17);
	st.push(18);
	st.push(19);
	st.push(20);
	st.push(21);
	st.push(22);

	try {
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';

		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
		std::cout << st.pop() << '\n';
	}
	catch (std::invalid_argument)
	{
		std::cout << "Error";
	}
}