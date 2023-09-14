#include "polynom/polynom.h"

using namespace pol;
using namespace std;

template<typename T>
Polynom<T>::Polynom(size_t size) : _size(size), _data(new T[size]()) {}

template class pol::Polynom<int>;

template<typename T>
Polynom<T>::Polynom(T* data, size_t size) : _data(data), _size(size) {}


template<typename T>
T& Polynom<T>::operator[](size_t index) {
	if (_size < index) {
		T zero = T(0);
		return zero;
	}
	return _data[index];
}

template<typename T>
size_t Polynom<T>:: size()  const {
	return _size;
}

//template<class T>
//void Polynom<T>::set(T data, int index) {
//	if (index > size) {
//		
//	}
//}

template<typename T>
Polynom<T>:: ~Polynom() {
	delete _data;
	_data = nullptr;
	_size = 0;
}

template<typename T>
void Polynom<T>::swap(Polynom<T>& a) {
	std::swap(_data, a._data);
	std::swap(_size, a._size);
}

template<typename T>
Polynom<T>& Polynom<T>::operator=(Polynom<T> a) {
	swap(a);
	return *this;
}

template<typename T>
Polynom<T>::Polynom(const Polynom& a) : _data(new T(a._size)), _size(a._size) {
	for (size_t i = 0; i < _size; i++) {
		_data[i] = a._data[i];
	}
}

//template<typename T>
//ostream& pol:: operator <<(ostream& stream, const Polynom<T>& a) {
//	for (size_t i = 0; i < _data.size(); ++i) {
//		if (i == 0) {
//			stream << _data[i];
//		}
//		else if (i == 1) {
//			stream << " + " << _data[i] << "*x";
//		}
//		else {
//			stream << " + " << _data[i] << "*x^" << i;
//		}
//	}
//	return stream;
//}