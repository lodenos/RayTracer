#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iomanip>

namespace RayTracer {
  using namespace std;

  template <typename T>
  struct Vector {
    public:
      T w;
      T x;
      T y;
      T z;
      // Operators
      friend ostream &operator<<(ostream &out, const Vector<T> &vector);
  };
}

#endif
