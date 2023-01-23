
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	template <class V>
	friend ostream& operator<<(ostream& o, const Array<V>& s);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(const T&);

		//Operator overloading
		T& operator[](int);
		T& operator[](int) const;
		Array<T>& operator+=(const T&);
		Array<T>& operator-=(const T&);

		//Misc
		int getSize() const;
		bool isFull() const;
		void clear();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array() {
	elements = new T[MAX_ARRAY];
	size = 0;
}

template <class T>
Array<T>::~Array() {
	delete [] elements;
}

template <class T>
void Array<T>::add(const T& t){
	if (size >= MAX_ARRAY)   return;

  	elements[size++] = t;
}

template <class T>
T& Array<T>::operator[](int index) {
  if (index < 0 || index >= size){
    cerr<< "ERROR: invalid index"<<endl;
    exit(1);
  }
  return elements[index];
}

template <class T>
T& Array<T>::operator[](int index) const {
  if (index < 0 || index >= size){
    cerr<< "ERROR: invalid index"<<endl;
    exit(1);
  }
  return elements[index];
}

template <class T>
Array<T>& Array<T>::operator+=(const T& t) {
	add(t);
	return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(const T& t) {
	if(size <= 0) { return *this; }

	int index = 0;
	for(index = 0; index < size; index++) {
		if(elements[index] == t) {
			break;
		}
	}

	if(index < size) {
		for(int i = index; i < size; i++) {
			elements[i] = elements[i+1];
		}
		size--;
	}

	return *this;
}

template <class T>
int Array<T>::getSize() const{
	return size;
}

template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARRAY;
}

template <class T>
void Array<T>::clear() {
	for(int i = 0; i < size; i++) {
		elements[i] = NULL;
	}
	size = 0;
} 

template <class T>
ostream& operator<<(ostream& out, Array<T>& list) {
	for(int i = 0; i < list.getSize(); i++) {
		out<<list[i]<<endl;
	}

  	return out;
}

#endif