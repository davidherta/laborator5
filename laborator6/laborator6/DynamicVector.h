#pragma once
#include <iostream>
#include <assert.h>

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;
public:
	DynamicVector(int = 10);
	DynamicVector(const DynamicVector&);
	~DynamicVector();

	DynamicVector& operator=(const DynamicVector&);
	T& operator[](int);

	void add(const T&);
	void remove(int);
	int getSize() const;

private:
	void resize(double = 2);
};

template<typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template<typename T>
DynamicVector<T>::DynamicVector(const DynamicVector &v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template<typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector &v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[v.capacity];
	for (int i = 0; i < v.capacity; i++)
	{
		this->elems[i] = v.elems[i];
	}

	return *this;
}
template<typename T>
DynamicVector<T> operator+(DynamicVector<T> v, const T &e)
{
	DynamicVector<T> res{ v };
	res.add(e);
	return res;
}

template<typename T>
DynamicVector<T> operator+(const T &e, DynamicVector<T> v)
{
	return v + e;
}

template<typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}
template<typename T>
void DynamicVector<T>::add(const T &e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size++] = e;
}

template<typename T>
void DynamicVector<T>::remove(int pos)
{
	for (int i = pos; i < this->getSize() - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;
}
template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= factor;

	T* els = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}
template <typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

inline void testVector()
{
	DynamicVector<int> v{};
	DynamicVector<int> v2{};
	assert(v.getSize() == 0);
	v.add(1);
	v.add(2);
	v.add(3);
	v = v + 4;
	v2 = 4 + v;
	assert(v2.getSize() == v.getSize() + 1);
	v = v + 5;
	v = v + 6;
	v = v + 7;
	v = v + 8;
	v = v + 9;
	v = v + 10;
	v = v + 11;
	assert(v.getSize() == 11);
}
