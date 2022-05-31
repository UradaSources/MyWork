#include "sprite.hpp"

Sprite::Sprite(SDLTexture texture, SDL_Rect rect) :
	m_raw(texture),
	m_rect(rect) {}
Sprite::Sprite(SDLTexture texture) :
	m_raw(texture)
{
	int w, h;
	if (SDL_QueryTexture(m_raw.get(), nullptr, nullptr, &w, &h))
		throw std::runtime_error(SDLErrorInfo());

	m_rect = { 0, 0, w, h };
}