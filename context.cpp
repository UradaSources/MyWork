#include <stdexcept>

#include "context.hpp"

// 获取即初始化
Context& Context::GetInstance()
{
	static Context _instance;
	return _instance;
}

Context::Context()
{
	int flags = SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_TIMER;
	if (SDL_Init(flags)) throw std::runtime_error(SDLErrorInfo());

	flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted & flags) != flags) throw std::runtime_error(IMGErrorInfo());

	SDL_DisplayMode dm;
	if (SDL_GetDesktopDisplayMode(0, &dm))
		throw std::runtime_error(SDLErrorInfo());

	int x = (dm.w - WindowWidth) / 2;
	int y = (dm.h - WindowHeight) / 2;

	flags = SDL_WINDOW_SHOWN;
	m_window = SDL_CreateWindow("binary search visual", x, y, WindowWidth, WindowHeight, flags);
	if (!m_window) throw std::runtime_error(SDLErrorInfo());

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	if (!m_renderer) throw std::runtime_error(SDLErrorInfo());
}
Context::~Context()
{
	// 释放sdl和img资产
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);

	IMG_Quit();
	SDL_Quit();
}

void Context::setDrawColor(uint8 r, uint8 g, uint8 b, uint8 a)
{
	SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void Context::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0x20, 0x20, 0x20, 0xFF);
	SDL_RenderClear(m_renderer);
}
void Context::present()
{
	SDL_RenderPresent(m_renderer);
}

void Context::draw(Sprite sprite, vec2i position)
{
	auto size = sprite.getSize();

	SDL_Rect dst = { position.x, position.y, size.x, size.y };
	SDL_RenderCopy(m_renderer, sprite._texture(), sprite._src(), &dst);
}
void Context::draw(Sprite sprite, vec2i position, vec2i size)
{
	SDL_Rect dst = { position.x, position.y, size.x, size.y };
	SDL_RenderCopy(m_renderer, sprite._texture(), sprite._src(), &dst);
}
