#include <stdexcept>

#include "context.hpp"

Context& Context::GetInstance()
{
	static Context _instance;
	return _instance;
}

Context::Context()
{
	int flag = SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_TIMER;
	if (SDL_Init(flag)) throw std::runtime_error(SDLErrorInfo());

	flag = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flag);
	if ((initted & flag) != flag) throw std::runtime_error(IMGErrorInfo());

	SDL_DisplayMode dm;
	if (SDL_GetDesktopDisplayMode(0, &dm))
		throw std::runtime_error(SDLErrorInfo());

	int x = (dm.w - WindowWidth) / 2;
	int y = (dm.h - WindowHeight) / 2;

	flag = SDL_WINDOW_SHOWN;
	m_window = SDL_CreateWindow("binary search visual", x, y, WindowWidth, WindowHeight, flag);
	if (!m_window) throw std::runtime_error(SDLErrorInfo());

	m_renderer = SDL_GetRenderer(m_window);
	if (!m_renderer) throw std::runtime_error(SDLErrorInfo());
}
Context::~Context()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Context::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0x64, 0x64, 0x64, 0xFF);
	SDL_RenderClear(m_renderer);
}
void Context::present()
{
	SDL_UpdateWindowSurface(m_window);
}

void Context::draw(Sprite sprite, vector2i position)
{
	auto size = sprite.getSize();
	SDL_Rect dst = { position.x, position.y, size.x, size.y };

	SDL_RenderCopy(m_renderer, sprite._texture(), sprite._src(), &dst);
	// SDL_BlitSurface(sprite.surface, sprite._src(), m_renderer, &dst);
}
