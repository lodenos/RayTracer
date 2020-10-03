#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Object.hpp"
#include "Vector.hpp"

namespace RayTracer {
  struct resolution_t {
    uint32_t height;
    uint32_t width;
  };

  class Camera : Object {
    public:
      // Constructor
      Camera();
      // Destructor
      ~Camera();
      // Methodes

    private:
      // Attributes
      resolution_t resolution;
      Vector<double> pixels;
      // FOV
      // distance
      // Methodes
  };
}

#endif
