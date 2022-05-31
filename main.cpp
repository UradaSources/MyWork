#include <algorithm>
#include <array>
#include <cstdio>
#include <ctime>
#include <list>
#include <stdexcept>
#include <memory>
#include <vector>

#include <SDL2/SDL.h>

#include "functions.hpp"
#include "context.hpp"

#define DEBUG

#include "binarySearchVisual.hpp"

int main(int argc, char** argv)
{
	try
	{
		Context& context = Context::GetInstance();

		SDL_Texture* raw = IMG_LoadTexture(context._renderer(), "./spriteSheet.png");
		std::shared_ptr<SDL_Texture> ptr(raw, SDL_DestroyTexture);

		Sprite s1{ ptr.get(), SDL_Rect{0,0,36,36} };

		SDL_Event e;

		int x, y;
		x = 0;
		y = 0;

		bool quit = false;
		while (!quit)
		{
			// Handle events on queue
			while (SDL_PollEvent(&e) != 0)
			{
				// User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_SPACE:
						x += 100;
						y += 100;
						break;
					}
				}
			}

			context.clear();
			context.draw(s1, {x, y});
			context.present();
		}

		return 0;
	}
	catch (std::exception& exp)
	{
		std::printf("%s", exp.what());
		return -1;
	}
}