#ifndef HEAD_SPRITE
#define HEAD_SPRITE

#include <stdexcept>
#include <memory>

#include <SDL.h>

#include "vec2.hpp"
#include "functions.hpp"

using SDLTexture = std::shared_ptr<SDL_Texture>;

class Sprite
{
private:
	SDLTexture m_raw;
	SDL_Rect m_rect;

public:
	Sprite(SDLTexture texture, SDL_Rect rect);
	Sprite(SDLTexture texture);

	Sprite(const Sprite&) = default;
	Sprite& operator=(const Sprite&) = default;

	vec2i getSize() { return vec2i{ m_rect.w, m_rect.h }; }

	SDLTexture _texture() { return m_raw; }

	SDL_Texture* _raw() { return m_raw.get(); }
	const SDL_Rect* _src() const { return &m_rect; }
};

#endif // !HEAD_SPRITE