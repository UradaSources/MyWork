#include "arrows.hpp"

Arrows::Arrows(Sprite sprite, vec2i position, float speed) :
	m_sprite(sprite),
	position(position),
	speed(speed) {}

void Arrows::start()
{
	target = position;
}

void Arrows::update(float dt)
{
	position = vec2i::Lerp(position, target, speed * dt);
}
