#include "Window.hpp"
#include <iostream>

#define DEFAULT_NAMES "RayTracer"
#define DEFAULT_HEIGHT 720
#define DEFAULT_WIDTH 1280

using namespace std;

namespace RayTracer {
  Window::Window() {
    this->window = SDL_CreateWindow(DEFAULT_NAMES, SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, DEFAULT_WIDTH, DEFAULT_HEIGHT, 0);
    if (this->window == nullptr) {
      cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
      exit(-1);
    }
  }

  Window::Window(const char* title) {
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, DEFAULT_WIDTH, DEFAULT_HEIGHT, 0);
    if (this->window == nullptr) {
      cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
      exit(-1);
    }
  }

  Window::Window(uint32_t height, uint32_t width) {
    this->window = SDL_CreateWindow(DEFAULT_NAMES, SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, static_cast<int>(width), static_cast<int>(height), 0);
    if (this->window == nullptr) {
      cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
      exit(-1);
    }
  }

  Window::Window(const char* title, uint32_t height, uint32_t width) {
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED, static_cast<int>(width), static_cast<int>(height), 0);
    if (this->window == nullptr) {
      cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
      exit(-1);
    }
  }

  Window::~Window() {
    SDL_DestroyWindow(this->window);
  }
}
