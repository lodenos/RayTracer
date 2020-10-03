#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL.h> 

namespace RayTracer {
  class Window {
    public:
      // Constructor
      Window();
      Window(const char* title);
      Window(uint32_t height, uint32_t width);
      Window(const char* title, uint32_t height, uint32_t width);
      // Destructor
      ~Window();
    private:
      SDL_Window *window;
  };
}

#endif
