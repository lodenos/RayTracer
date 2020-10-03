#include "RayTracer.hpp"
#include <unistd.h>

using namespace RayTracer;

void __attribute__((constructor)) constructor(void); 
void __attribute__((destructor)) destructor(void); 

int main() {
  Window window = Window();
  sleep(1000);
  return 0;
}

void constructor() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    exit(-1);
  }
}

void destructor() {
  SDL_Quit();
}
