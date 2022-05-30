#include "sprite.hpp"

Sprite::Sprite(SDL_Texture* texture, SDL_Rect rect) :
	m_texture(texture),
	m_rect(rect) {}
Sprite::Sprite(SDL_Texture* texture) :
	m_texture(texture)
{
	int w, h;
	if (SDL_QueryTexture(m_texture, nullptr, nullptr, &w, &h))
		throw std::runtime_error(SDLErrorInfo());

	m_rect = { 0, 0, w, h };
}