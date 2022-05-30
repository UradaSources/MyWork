#ifndef HEAD_SPRITE
#define HEAD_SPRITE

#include <stdexcept>

#include <SDL.h>

#include "vec2.hpp"
#include "functions.hpp"

class Sprite
{
private:
	SDL_Texture* m_texture;
	SDL_Rect m_rect;

public:
	Sprite(SDL_Texture* texture, SDL_Rect rect);
	Sprite(SDL_Texture* texture);

	Sprite(const Sprite&) = default;
	Sprite& operator=(const Sprite&) = default;

	vec2i getSize() { return vec2i{ m_rect.w, m_rect.h }; }

	SDL_Texture* _texture() { return m_texture; }
	const SDL_Rect* _src() const { return &m_rect; }
};

#endif // !HEAD_SPRITE