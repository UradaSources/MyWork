#include "unit.hpp"
#include "binarySearchVisual.hpp"

Unit::Unit(BinarySearchVisual& visual, vector2i position):
	m_visual(visual),
	m_value(0),
	m_index(-1),
	m_position(position) {}

void Unit::init(int index, int value)
{
	m_index = index;
	m_value = value;
}

void Unit::reset(int value)
{
	m_value = value;
}

void Unit::start() {}

void Unit::update(float dt)
{
	Context& context = Context::GetInstance();
	context.draw(m_visual.getUnitSprite(), m_position);
}
