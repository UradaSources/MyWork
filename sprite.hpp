#ifndef HEAD_SPRITE
#define HEAD_SPRITE

#include <stdexcept>

#include <SDL.h>

#include "functions.hpp"

class Sprite
{
private:
	SDL_Texture* m_texture;
	SDL_Rect m_rect;

public:
	Sprite(SDL_Texture* texture, SDL_Rect rect) :
		m_texture(texture),
		m_rect(rect) {}
	Sprite(SDL_Texture* texture) :
		m_texture(texture)
	{
		int w, h;
		if (SDL_QueryTexture(m_texture, nullptr, nullptr, &w, &h))
			throw std::runtime_error(SDLErrorInfo());
		
		m_rect = { 0, 0, w, h };
	}

	vector2i getSize() { return vector2i{ m_rect.w, m_rect.h }; }

	SDL_Texture* _texture() { return m_texture; }
	const SDL_Rect* _src() const { return &m_rect; }
};

#endif // !HEAD_SPRITE