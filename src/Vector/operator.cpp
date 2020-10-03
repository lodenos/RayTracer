#include "Vector.hpp"

namespace RayTracer {
  using namespace std;

  template <typename T>
  ostream &operator<<(ostream &out, const Vector<T> &vector) {
    out << setprecision(1000)
      << "w: " << vector.w << endl 
      << "x: " << vector.x << endl
      << "y: " << vector.y << endl
      << "z: " << vector.z << endl;
    return out;
  }
}
