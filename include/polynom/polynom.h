#pragma once
#include <iostream>

namespace pol {
    template<typename T>
    class Polynom {
      private:
         T* _data;
         size_t _size;
      public:
          Polynom(size_t size) : _size(size), _data(new T[size]()) {}
          Polynom(T* data, size_t size) :  _data(data), _size(size) {}
          size_t size() const {
              return _size;
          }
          ~Polynom() {
              delete [] _data;
              _data = nullptr;
              _size = 0;
          }
          Polynom(const Polynom& a) : _data(new T[a._size]), _size(a._size) {
              for (size_t i = 0; i < _size; i++) {
                  _data[i] = a[i];
              }
          }
          Polynom<T>& operator=(Polynom<T> a) {
              swap(a);
              return *this;
          }
          void swap(Polynom<T>& a) {
              std::swap(_data, a._data);
              std::swap(_size, a._size);
          }
          T operator[](size_t index) const {
              if (_size <= index) {
                  return 0;
              }
              return _data[index];
          }
          void set(T data, size_t index) {
              _data[index] = data;
          }
          void expand(size_t size) {
              auto temp = (new T[size]());
              for (size_t i = 0; i < _size; i++) {
                  temp[i] = _data[i];
              }
              delete[] _data;
              _data = temp;
              _size = size;
          }
          Polynom<T>& operator+= (const Polynom<T>& a) {
              if (a.size() > _size) {
                  expand(a.size());
              }
              for (size_t i = 0; i < a._size; i++) {
                  _data[i] += a[i];
              }
              return *this;
          }
          Polynom<T>& operator-= (const Polynom<T>& a) {
              if (a.size() > _size) {
                  expand(a.size());
              }
              for (size_t i = 0; i < a._size; i++) {
                  _data[i] -= a[i];
              }
              return *this;
          }
          Polynom<T> operator- (const Polynom<T>& a) const {
              Polynom<T> copy(*this);
              return copy -= a;
          }
          Polynom<T> operator+ (Polynom<T> a)  const {
              return a+=*this;
          }
          Polynom<T>& operator*(const T& a) {
              for (size_t i = 0; i < _size; i++) {
                  _data[i] *= a;
              }
              return *this;
          }
          T calculation_polynom_x(const T& x) {
              T sum = 0;
              for (size_t i = 0; i < _size; i++) {
                  sum += _data[i] * pow(x, i);
              }
              return sum;
          }
          void shrink_to_fit(){
              for (size_t i = _size-1; i > 0; i--) {
                  if (_data[i] != 0) {
                      i++;
                      auto temp = (new T[i]());
                      for (size_t j = 0; j < i; j++) {
                          temp[j] = _data[j];
                      }
                      delete[] _data;
                      _data = temp;
                      _size = i;
                      break;
                  }
              }
          }
    };

    template<typename T>
    std::ostream& operator << (std::ostream& stream, const Polynom<T>& a) {
	    for (size_t i = 0; i < a.size(); ++i) {
	    	if (i == 0) {
		    	stream << a[i];
		    }
		    else if (i == 1) {
			    stream << " + " << a[i] << "*x";
		    }
		    else {
		    	stream << " + " << a[i] << "*x^" << i;
	    	}
	    }
	    return stream;
    }
 }
