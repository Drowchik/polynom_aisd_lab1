#pragma once
#include <iostream>

namespace pol {
    template<typename T>
    class Polynom {
     private:
          T* _data;
          size_t _size;
      public:
          Polynom(size_t size);
          Polynom(T* data, size_t size);
          size_t size() const;
          ~Polynom(); 
          Polynom(const Polynom& a); 
          Polynom<T>& operator=(const Polynom<T> a);
          void swap(Polynom& a);
          T& operator[](size_t index);
          /*void set(T data, int index);*/
    };
 }
