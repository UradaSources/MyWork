#ifndef HEAD_CONTEXT
#define HEAD_CONTEXT

#include <SDL.h>
#include <SDL_image.h>

#include "sprite.hpp"
#include "vector2.hpp"
#include "functions.hpp"

class Context
{
public:
	const int WindowWidth = 800;
	const int WindowHeight = 600;

	static Context& GetInstance();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	Context();
	~Context();

public:
	Context(const Context&) = delete;
	Context& operator=(const Context&) = delete;

	void clear();
	void present();

	void draw(Sprite sprite, vector2i position);

	SDL_Renderer* _renderer() { return m_renderer; }
};

#endif // !HEAD_CONTEXT