#ifndef HEAD_FUNCTIONS
#define HEAD_FUNCTIONS

#include <memory>

#include <SDL.h>

using uint8 = std::uint8_t;

int Random(int max, int min);

const char* _GenerateInfo(int lineNumber, const char* content, const char* fileName);

#define ErrorInfo(content) _GenerateInfo(__LINE__, content, __FILE__)
#define SDLErrorInfo() _GenerateInfo(__LINE__, SDL_GetError(), __FILE__)
#define IMGErrorInfo() _GenerateInfo(__LINE__, IMG_GetError(), __FILE__)

/*
if (SDL_Init(0)) throw exc(SDLErrorInfo());
*/

#endif
