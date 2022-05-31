#ifndef HEAD_CONTEXT
#define HEAD_CONTEXT

#include <SDL.h>
#include <SDL_image.h>

#include "sprite.hpp"
#include "vec2.hpp"
#include "functions.hpp"

using SDLTexture = std::shared_ptr<SDL_Texture>;

class Context
{
public:
	const int WindowWidth = 1280;
	const int WindowHeight = 720;

	static Context& GetInstance();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	Context();
	~Context();

public:
	Context(const Context&) = delete;
	Context& operator=(const Context&) = delete;

	// 从文件加载纹理
	SDLTexture loadTextureFromFile(const char* filePath);

	// 清屏
	void clear();
	// 刷屏屏幕
	void present();

	// 设置绘制颜色
	void setDrawColor(uint8 r, uint8 g, uint8 b, uint8 a = 255);

	// 在屏幕特定位置绘制精灵
	void draw(Sprite sprite, vec2i position);
	// 以特定大小在屏幕特定位置上绘制精灵
	void draw(Sprite sprite, vec2i position, vec2i size);

	SDL_Renderer* _renderer() { return m_renderer; }
};

#endif // !HEAD_CONTEXT