#pragma once

template<typename T> class Vector {
private:
	T* elements;
	int size;
	int cappasity;
public:
	Vector<T>() : size{ 0 }, cappasity{ 10 }{
		elements = new T[cappasity];
	}

	Vector<T>(T* elements, int cappasity, int size) : size{ size }, cappasity{ cappasity } {
		elements = new T[cappasity];
		for (size_t i = 0; i < size; i++) {
			this->elements[i] = elements[i];
		}
	}

	Vector<T>(const Vector<T>& other) {
		copy(other);
	}

	Vector<T>& operator=(const Vector<T>& other) {
		if (this != &other) {
			free();
			copy(other);
		}
		return *this;
	}

	~Vector() {
		free();
	}

	void free() {
		delete[] elements;
	}

	void copy(const Vector<T>& other) {
		cappasity = other.cappasity;
		size = other.size;
		elements = new T[cappasity];
		for (size_t i = 0; i < size; i++) {
			this->elements[i] = other.elements[i];
		}
	}

	void resize() {
		cappasity *= 2;
		T* tmp = new T[cappasity];
		for (size_t i = 0; i < size; i++){
			tmp[i] = elements[i];
		}
		delete[] elements;
		elements = new T[cappasity];
		elements = tmp;
		tmp = nullptr;
	}

	void push(const T& other) {
		if (size == cappasity) {
			resize();
		}
		elements[size] = other;
		size++;
	}

	void print() {
		for (size_t i = 0; i < size; i++) {
			std::cout << elements[i];
		}
	}

	void pop() {
		size--;
	}

	T& operator[](int index) {
		return elements[index];
	}
};