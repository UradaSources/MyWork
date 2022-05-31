#ifndef HEAD_ARROWS
#define HEAD_ARROWS

#include "vec2.hpp"
#include "sprite.hpp"
#include "activeObject.hpp"

class Arrows : public ActiveObject
{
private:
	Sprite m_sprite;

public:
	vec2i position;
	vec2i target;

	float speed;

public:
	Arrows(Sprite sprite, vec2i position, float speed = 10.0f);
	~Arrows() = default;

	virtual void start();
	virtual void update(float dt);
};

#endif
